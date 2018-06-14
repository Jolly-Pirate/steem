
#include <steem/plugins/rc/rc_utility.hpp>

#include <fc/reflect/variant.hpp>
#include <fc/uint128.hpp>

namespace steem { namespace plugins { namespace rc {

using fc::uint128_t;

int64_t compute_rc_cost_of_resource(
   const rc_curve_params& curve_params,
   int64_t current_pool,
   int64_t resource_count,
   int64_t rc_regen
   )
{
   /*
   ilog( "compute_rc_cost_of_resources( ${params}, ${pool}, ${res} )",
      ("params", curve_params)
      ("pool", current_pool)
      ("res", resource_count) );
   */
   FC_ASSERT( rc_regen > 0 );

   if( resource_count <= 0 )
   {
      if( resource_count < 0 )
         return -compute_rc_cost_of_resource( curve_params, current_pool, -resource_count, rc_regen );
      return 0;
   }
   uint128_t num = uint128_t( rc_regen );
   num *= curve_params.coeff_a;
   // rc_regen * coeff_a is already risking overflowing 128 bits,
   //   so shift it immediately before multiplying by resource_count
   num >>= curve_params.shift;
   // err on the side of rounding not in the user's favor
   num += 1;
   num *= uint64_t( resource_count );

   uint128_t denom = uint128_t( curve_params.coeff_b );

   // Negative pool doesn't increase price beyond p_max
   //   i.e. define p(x) = p(0) for all x < 0
   denom += (current_pool > 0) ? uint64_t(current_pool) : uint64_t(0);
   uint128_t num_denom = num / denom;
   // Add 1 to avoid 0 result in case of various rounding issues,
   // err on the side of rounding not in the user's favor
   return num_denom.to_uint64()+1;
}

int64_t compute_pool_decay(
   const rc_decay_params& decay_params,
   int64_t current_pool,
   uint32_t dt
   )
{
   /*
   ilog( "compute_pool_decay( ${params}, ${pool}, ${dt} )",
      ("params", decay_params)
      ("pool", current_pool)
      ("dt", dt) );
   */

   if( current_pool < 0 )
      return -compute_pool_decay( decay_params, -current_pool, dt );

   uint128_t decay_amount = uint64_t( decay_params.decay_per_time_unit ) * uint64_t( dt );
   decay_amount *= uint64_t( current_pool );
   decay_amount >>= decay_params.decay_per_time_unit_denom_shift;
   uint64_t result = decay_amount.to_uint64();
   return (
           (result > uint64_t( current_pool ))
           ? current_pool
           : int64_t(result)
          );
}

} } }
