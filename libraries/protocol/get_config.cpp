#include <steem/protocol/get_config.hpp>
#include <steem/protocol/config.hpp>
#include <steem/protocol/asset.hpp>
#include <steem/protocol/types.hpp>
#include <steem/protocol/version.hpp>

namespace steem { namespace protocol {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

#ifdef IS_TEST_NET
   result[ "IS_TEST_NET" ] = true;
   result["TESTNET_BLOCK_LIMIT"] = TESTNET_BLOCK_LIMIT;
#else
   result[ "IS_TEST_NET" ] = false;
#endif
#ifdef STEEM_ENABLE_SMT
   result[ "STEEM_ENABLE_SMT" ] = true;
   result["SMT_MAX_VOTABLE_ASSETS"] = SMT_MAX_VOTABLE_ASSETS;
   result["SMT_VESTING_WITHDRAW_INTERVAL_SECONDS"] = SMT_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["SMT_UPVOTE_LOCKOUT"] = SMT_UPVOTE_LOCKOUT;
   result["SMT_EMISSION_MIN_INTERVAL_SECONDS"] = SMT_EMISSION_MIN_INTERVAL_SECONDS;
   result["SMT_EMIT_INDEFINITELY"] = SMT_EMIT_INDEFINITELY;
   result["SMT_MAX_NOMINAL_VOTES_PER_DAY"] = SMT_MAX_NOMINAL_VOTES_PER_DAY;
   result["SMT_MAX_VOTES_PER_REGENERATION"] = SMT_MAX_VOTES_PER_REGENERATION;
   result["SMT_DEFAULT_VOTES_PER_REGEN_PERIOD"] = SMT_DEFAULT_VOTES_PER_REGEN_PERIOD;
   result["SMT_DEFAULT_PERCENT_CURATION_REWARDS"] = SMT_DEFAULT_PERCENT_CURATION_REWARDS;
#else
   result[ "STEEM_ENABLE_SMT" ] = false;
#endif

   result["SBD_SYMBOL"] = SBD_SYMBOL;
   result["STEEM_INITIAL_VOTE_POWER_RATE"] = STEEM_INITIAL_VOTE_POWER_RATE;
   result["STEEM_REDUCED_VOTE_POWER_RATE"] = STEEM_REDUCED_VOTE_POWER_RATE;
   result["STEEM_100_PERCENT"] = STEEM_100_PERCENT;
   result["STEEM_1_PERCENT"] = STEEM_1_PERCENT;
   result["STEEM_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD"] = STEEM_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD;
   result["STEEM_ACTIVE_CHALLENGE_COOLDOWN"] = STEEM_ACTIVE_CHALLENGE_COOLDOWN;
   result["STEEM_ACTIVE_CHALLENGE_FEE"] = STEEM_ACTIVE_CHALLENGE_FEE;
   result["STEEM_ADDRESS_PREFIX"] = STEEM_ADDRESS_PREFIX;
   result["STEEM_APR_PERCENT_MULTIPLY_PER_BLOCK"] = STEEM_APR_PERCENT_MULTIPLY_PER_BLOCK;
   result["STEEM_APR_PERCENT_MULTIPLY_PER_HOUR"] = STEEM_APR_PERCENT_MULTIPLY_PER_HOUR;
   result["STEEM_APR_PERCENT_MULTIPLY_PER_ROUND"] = STEEM_APR_PERCENT_MULTIPLY_PER_ROUND;
   result["STEEM_APR_PERCENT_SHIFT_PER_BLOCK"] = STEEM_APR_PERCENT_SHIFT_PER_BLOCK;
   result["STEEM_APR_PERCENT_SHIFT_PER_HOUR"] = STEEM_APR_PERCENT_SHIFT_PER_HOUR;
   result["STEEM_APR_PERCENT_SHIFT_PER_ROUND"] = STEEM_APR_PERCENT_SHIFT_PER_ROUND;
   result["STEEM_BANDWIDTH_AVERAGE_WINDOW_SECONDS"] = STEEM_BANDWIDTH_AVERAGE_WINDOW_SECONDS;
   result["STEEM_BANDWIDTH_PRECISION"] = STEEM_BANDWIDTH_PRECISION;
   result["STEEM_BLOCKCHAIN_PRECISION"] = STEEM_BLOCKCHAIN_PRECISION;
   result["STEEM_BLOCKCHAIN_PRECISION_DIGITS"] = STEEM_BLOCKCHAIN_PRECISION_DIGITS;
   result["STEEM_BLOCKCHAIN_HARDFORK_VERSION"] = STEEM_BLOCKCHAIN_HARDFORK_VERSION;
   result["STEEM_BLOCKCHAIN_VERSION"] = STEEM_BLOCKCHAIN_VERSION;
   result["STEEM_BLOCK_INTERVAL"] = STEEM_BLOCK_INTERVAL;
   result["STEEM_BLOCKS_PER_DAY"] = STEEM_BLOCKS_PER_DAY;
   result["STEEM_BLOCKS_PER_HOUR"] = STEEM_BLOCKS_PER_HOUR;
   result["STEEM_BLOCKS_PER_YEAR"] = STEEM_BLOCKS_PER_YEAR;
   result["STEEM_CASHOUT_WINDOW_SECONDS"] = STEEM_CASHOUT_WINDOW_SECONDS;
   result["STEEM_CASHOUT_WINDOW_SECONDS_PRE_HF12"] = STEEM_CASHOUT_WINDOW_SECONDS_PRE_HF12;
   result["STEEM_CASHOUT_WINDOW_SECONDS_PRE_HF17"] = STEEM_CASHOUT_WINDOW_SECONDS_PRE_HF17;
   result["STEEM_CHAIN_ID"] = STEEM_CHAIN_ID;
   result["STEEM_COMMENT_REWARD_FUND_NAME"] = STEEM_COMMENT_REWARD_FUND_NAME;
   result["STEEM_CONTENT_APR_PERCENT"] = STEEM_CONTENT_APR_PERCENT;
   result["STEEM_CONTENT_CONSTANT_HF0"] = STEEM_CONTENT_CONSTANT_HF0;
   result["STEEM_CONTENT_REWARD_PERCENT"] = STEEM_CONTENT_REWARD_PERCENT;
   result["STEEM_CONVERSION_DELAY"] = STEEM_CONVERSION_DELAY;
   result["STEEM_CONVERSION_DELAY_PRE_HF_16"] = STEEM_CONVERSION_DELAY_PRE_HF_16;
   result["STEEM_CREATE_ACCOUNT_DELEGATION_RATIO"] = STEEM_CREATE_ACCOUNT_DELEGATION_RATIO;
   result["STEEM_CREATE_ACCOUNT_DELEGATION_TIME"] = STEEM_CREATE_ACCOUNT_DELEGATION_TIME;
   result["STEEM_CREATE_ACCOUNT_WITH_STEEM_MODIFIER"] = STEEM_CREATE_ACCOUNT_WITH_STEEM_MODIFIER;
   result["STEEM_CURATE_APR_PERCENT"] = STEEM_CURATE_APR_PERCENT;
   result["STEEM_DEFAULT_SBD_INTEREST_RATE"] = STEEM_DEFAULT_SBD_INTEREST_RATE;
   result["STEEM_EQUIHASH_K"] = STEEM_EQUIHASH_K;
   result["STEEM_EQUIHASH_N"] = STEEM_EQUIHASH_N;
   result["STEEM_FEED_HISTORY_WINDOW"] = STEEM_FEED_HISTORY_WINDOW;
   result["STEEM_FEED_HISTORY_WINDOW_PRE_HF_16"] = STEEM_FEED_HISTORY_WINDOW_PRE_HF_16;
   result["STEEM_FEED_INTERVAL_BLOCKS"] = STEEM_FEED_INTERVAL_BLOCKS;
   result["STEEM_GENESIS_TIME"] = STEEM_GENESIS_TIME;
   result["STEEM_HARDFORK_REQUIRED_WITNESSES"] = STEEM_HARDFORK_REQUIRED_WITNESSES;
   result["STEEM_INFLATION_NARROWING_PERIOD"] = STEEM_INFLATION_NARROWING_PERIOD;
   result["STEEM_INFLATION_RATE_START_PERCENT"] = STEEM_INFLATION_RATE_START_PERCENT;
   result["STEEM_INFLATION_RATE_STOP_PERCENT"] = STEEM_INFLATION_RATE_STOP_PERCENT;
   result["STEEM_INIT_MINER_NAME"] = STEEM_INIT_MINER_NAME;
   result["STEEM_INIT_PUBLIC_KEY_STR"] = STEEM_INIT_PUBLIC_KEY_STR;
#if 0
   // do not expose private key, period.
   // we need this line present but inactivated so CI check for all constants in config.hpp doesn't complain.
   result["STEEM_INIT_PRIVATE_KEY"] = STEEM_INIT_PRIVATE_KEY;
#endif
   result["STEEM_INIT_SUPPLY"] = STEEM_INIT_SUPPLY;
   result["STEEM_INIT_TIME"] = STEEM_INIT_TIME;
   result["STEEM_IRREVERSIBLE_THRESHOLD"] = STEEM_IRREVERSIBLE_THRESHOLD;
   result["STEEM_LIQUIDITY_APR_PERCENT"] = STEEM_LIQUIDITY_APR_PERCENT;
   result["STEEM_LIQUIDITY_REWARD_BLOCKS"] = STEEM_LIQUIDITY_REWARD_BLOCKS;
   result["STEEM_LIQUIDITY_REWARD_PERIOD_SEC"] = STEEM_LIQUIDITY_REWARD_PERIOD_SEC;
   result["STEEM_LIQUIDITY_TIMEOUT_SEC"] = STEEM_LIQUIDITY_TIMEOUT_SEC;
   result["STEEM_MAX_ACCOUNT_CREATION_FEE"] = STEEM_MAX_ACCOUNT_CREATION_FEE;
   result["STEEM_MAX_ACCOUNT_NAME_LENGTH"] = STEEM_MAX_ACCOUNT_NAME_LENGTH;
   result["STEEM_MAX_ACCOUNT_WITNESS_VOTES"] = STEEM_MAX_ACCOUNT_WITNESS_VOTES;
   result["STEEM_MAX_ASSET_WHITELIST_AUTHORITIES"] = STEEM_MAX_ASSET_WHITELIST_AUTHORITIES;
   result["STEEM_MAX_AUTHORITY_MEMBERSHIP"] = STEEM_MAX_AUTHORITY_MEMBERSHIP;
   result["STEEM_MAX_BLOCK_SIZE"] = STEEM_MAX_BLOCK_SIZE;
   result["STEEM_SOFT_MAX_BLOCK_SIZE"] = STEEM_SOFT_MAX_BLOCK_SIZE;
   result["STEEM_MAX_CASHOUT_WINDOW_SECONDS"] = STEEM_MAX_CASHOUT_WINDOW_SECONDS;
   result["STEEM_MAX_COMMENT_DEPTH"] = STEEM_MAX_COMMENT_DEPTH;
   result["STEEM_MAX_COMMENT_DEPTH_PRE_HF17"] = STEEM_MAX_COMMENT_DEPTH_PRE_HF17;
   result["STEEM_MAX_FEED_AGE_SECONDS"] = STEEM_MAX_FEED_AGE_SECONDS;
   result["STEEM_MAX_INSTANCE_ID"] = STEEM_MAX_INSTANCE_ID;
   result["STEEM_MAX_MEMO_SIZE"] = STEEM_MAX_MEMO_SIZE;
   result["STEEM_MAX_WITNESSES"] = STEEM_MAX_WITNESSES;
   result["STEEM_MAX_MINER_WITNESSES_HF0"] = STEEM_MAX_MINER_WITNESSES_HF0;
   result["STEEM_MAX_MINER_WITNESSES_HF17"] = STEEM_MAX_MINER_WITNESSES_HF17;
   result["STEEM_MAX_PERMLINK_LENGTH"] = STEEM_MAX_PERMLINK_LENGTH;
   result["STEEM_MAX_PROXY_RECURSION_DEPTH"] = STEEM_MAX_PROXY_RECURSION_DEPTH;
   result["STEEM_MAX_RATION_DECAY_RATE"] = STEEM_MAX_RATION_DECAY_RATE;
   result["STEEM_MAX_RESERVE_RATIO"] = STEEM_MAX_RESERVE_RATIO;
   result["STEEM_MAX_RUNNER_WITNESSES_HF0"] = STEEM_MAX_RUNNER_WITNESSES_HF0;
   result["STEEM_MAX_RUNNER_WITNESSES_HF17"] = STEEM_MAX_RUNNER_WITNESSES_HF17;
   result["STEEM_MAX_SATOSHIS"] = STEEM_MAX_SATOSHIS;
   result["STEEM_MAX_SHARE_SUPPLY"] = STEEM_MAX_SHARE_SUPPLY;
   result["STEEM_MAX_SIG_CHECK_DEPTH"] = STEEM_MAX_SIG_CHECK_DEPTH;
   result["STEEM_MAX_SIG_CHECK_ACCOUNTS"] = STEEM_MAX_SIG_CHECK_ACCOUNTS;
   result["STEEM_MAX_TIME_UNTIL_EXPIRATION"] = STEEM_MAX_TIME_UNTIL_EXPIRATION;
   result["STEEM_MAX_TRANSACTION_SIZE"] = STEEM_MAX_TRANSACTION_SIZE;
   result["STEEM_MAX_UNDO_HISTORY"] = STEEM_MAX_UNDO_HISTORY;
   result["STEEM_MAX_URL_LENGTH"] = STEEM_MAX_URL_LENGTH;
   result["STEEM_MAX_VOTE_CHANGES"] = STEEM_MAX_VOTE_CHANGES;
   result["STEEM_MAX_VOTED_WITNESSES_HF0"] = STEEM_MAX_VOTED_WITNESSES_HF0;
   result["STEEM_MAX_VOTED_WITNESSES_HF17"] = STEEM_MAX_VOTED_WITNESSES_HF17;
   result["STEEM_MAX_WITHDRAW_ROUTES"] = STEEM_MAX_WITHDRAW_ROUTES;
   result["STEEM_MAX_WITNESS_URL_LENGTH"] = STEEM_MAX_WITNESS_URL_LENGTH;
   result["STEEM_MIN_ACCOUNT_CREATION_FEE"] = STEEM_MIN_ACCOUNT_CREATION_FEE;
   result["STEEM_MIN_ACCOUNT_NAME_LENGTH"] = STEEM_MIN_ACCOUNT_NAME_LENGTH;
   result["STEEM_MIN_BLOCK_SIZE_LIMIT"] = STEEM_MIN_BLOCK_SIZE_LIMIT;
   result["STEEM_MIN_BLOCK_SIZE"] = STEEM_MIN_BLOCK_SIZE;
   result["STEEM_MIN_CONTENT_REWARD"] = STEEM_MIN_CONTENT_REWARD;
   result["STEEM_MIN_CURATE_REWARD"] = STEEM_MIN_CURATE_REWARD;
   result["STEEM_MIN_PERMLINK_LENGTH"] = STEEM_MIN_PERMLINK_LENGTH;
   result["STEEM_MIN_REPLY_INTERVAL"] = STEEM_MIN_REPLY_INTERVAL;
   result["STEEM_MIN_REPLY_INTERVAL_HF20"] = STEEM_MIN_REPLY_INTERVAL_HF20;
   result["STEEM_MIN_ROOT_COMMENT_INTERVAL"] = STEEM_MIN_ROOT_COMMENT_INTERVAL;
   result["STEEM_MIN_VOTE_INTERVAL_SEC"] = STEEM_MIN_VOTE_INTERVAL_SEC;
   result["STEEM_MINER_ACCOUNT"] = STEEM_MINER_ACCOUNT;
   result["STEEM_MINER_PAY_PERCENT"] = STEEM_MINER_PAY_PERCENT;
   result["STEEM_MIN_FEEDS"] = STEEM_MIN_FEEDS;
   result["STEEM_MINING_REWARD"] = STEEM_MINING_REWARD;
   result["STEEM_MINING_TIME"] = STEEM_MINING_TIME;
   result["STEEM_MIN_LIQUIDITY_REWARD"] = STEEM_MIN_LIQUIDITY_REWARD;
   result["STEEM_MIN_LIQUIDITY_REWARD_PERIOD_SEC"] = STEEM_MIN_LIQUIDITY_REWARD_PERIOD_SEC;
   result["STEEM_MIN_PAYOUT_SBD"] = STEEM_MIN_PAYOUT_SBD;
   result["STEEM_MIN_POW_REWARD"] = STEEM_MIN_POW_REWARD;
   result["STEEM_MIN_PRODUCER_REWARD"] = STEEM_MIN_PRODUCER_REWARD;
   result["STEEM_MIN_TRANSACTION_EXPIRATION_LIMIT"] = STEEM_MIN_TRANSACTION_EXPIRATION_LIMIT;
   result["STEEM_MIN_TRANSACTION_SIZE_LIMIT"] = STEEM_MIN_TRANSACTION_SIZE_LIMIT;
   result["STEEM_MIN_UNDO_HISTORY"] = STEEM_MIN_UNDO_HISTORY;
   result["STEEM_NULL_ACCOUNT"] = STEEM_NULL_ACCOUNT;
   result["STEEM_NUM_INIT_MINERS"] = STEEM_NUM_INIT_MINERS;
   result["STEEM_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM"] = STEEM_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM;
   result["STEEM_OWNER_AUTH_RECOVERY_PERIOD"] = STEEM_OWNER_AUTH_RECOVERY_PERIOD;
   result["STEEM_OWNER_CHALLENGE_COOLDOWN"] = STEEM_OWNER_CHALLENGE_COOLDOWN;
   result["STEEM_OWNER_CHALLENGE_FEE"] = STEEM_OWNER_CHALLENGE_FEE;
   result["STEEM_OWNER_UPDATE_LIMIT"] = STEEM_OWNER_UPDATE_LIMIT;
   result["STEEM_POST_AVERAGE_WINDOW"] = STEEM_POST_AVERAGE_WINDOW;
   result["STEEM_POST_REWARD_FUND_NAME"] = STEEM_POST_REWARD_FUND_NAME;
   result["STEEM_POST_WEIGHT_CONSTANT"] = STEEM_POST_WEIGHT_CONSTANT;
   result["STEEM_POW_APR_PERCENT"] = STEEM_POW_APR_PERCENT;
   result["STEEM_PRODUCER_APR_PERCENT"] = STEEM_PRODUCER_APR_PERCENT;
   result["STEEM_PROXY_TO_SELF_ACCOUNT"] = STEEM_PROXY_TO_SELF_ACCOUNT;
   result["STEEM_SBD_INTEREST_COMPOUND_INTERVAL_SEC"] = STEEM_SBD_INTEREST_COMPOUND_INTERVAL_SEC;
   result["STEEM_SECONDS_PER_YEAR"] = STEEM_SECONDS_PER_YEAR;
   result["STEEM_RECENT_RSHARES_DECAY_TIME_HF19"] = STEEM_RECENT_RSHARES_DECAY_TIME_HF19;
   result["STEEM_RECENT_RSHARES_DECAY_TIME_HF17"] = STEEM_RECENT_RSHARES_DECAY_TIME_HF17;
   result["STEEM_REVERSE_AUCTION_WINDOW_SECONDS_HF6"] = STEEM_REVERSE_AUCTION_WINDOW_SECONDS_HF6;
   result["STEEM_REVERSE_AUCTION_WINDOW_SECONDS_HF20"] = STEEM_REVERSE_AUCTION_WINDOW_SECONDS_HF20;
   result["STEEM_ROOT_POST_PARENT"] = STEEM_ROOT_POST_PARENT;
   result["STEEM_SAVINGS_WITHDRAW_REQUEST_LIMIT"] = STEEM_SAVINGS_WITHDRAW_REQUEST_LIMIT;
   result["STEEM_SAVINGS_WITHDRAW_TIME"] = STEEM_SAVINGS_WITHDRAW_TIME;
   result["STEEM_SBD_START_PERCENT_HF14"] = STEEM_SBD_START_PERCENT_HF14;
   result["STEEM_SBD_START_PERCENT_HF20"] = STEEM_SBD_START_PERCENT_HF20;
   result["STEEM_SBD_STOP_PERCENT_HF14"] = STEEM_SBD_STOP_PERCENT_HF14;
   result["STEEM_SBD_STOP_PERCENT_HF20"] = STEEM_SBD_STOP_PERCENT_HF20;
   result["STEEM_SECOND_CASHOUT_WINDOW"] = STEEM_SECOND_CASHOUT_WINDOW;
   result["STEEM_SOFT_MAX_COMMENT_DEPTH"] = STEEM_SOFT_MAX_COMMENT_DEPTH;
   result["STEEM_START_MINER_VOTING_BLOCK"] = STEEM_START_MINER_VOTING_BLOCK;
   result["STEEM_START_VESTING_BLOCK"] = STEEM_START_VESTING_BLOCK;
   result["STEEM_TEMP_ACCOUNT"] = STEEM_TEMP_ACCOUNT;
   result["STEEM_UPVOTE_LOCKOUT_HF7"] = STEEM_UPVOTE_LOCKOUT_HF7;
   result["STEEM_UPVOTE_LOCKOUT_HF17"] = STEEM_UPVOTE_LOCKOUT_HF17;
   result["STEEM_UPVOTE_LOCKOUT_SECONDS"] = STEEM_UPVOTE_LOCKOUT_SECONDS;
   result["STEEM_VESTING_FUND_PERCENT"] = STEEM_VESTING_FUND_PERCENT;
   result["STEEM_VESTING_WITHDRAW_INTERVALS"] = STEEM_VESTING_WITHDRAW_INTERVALS;
   result["STEEM_VESTING_WITHDRAW_INTERVALS_PRE_HF_16"] = STEEM_VESTING_WITHDRAW_INTERVALS_PRE_HF_16;
   result["STEEM_VESTING_WITHDRAW_INTERVAL_SECONDS"] = STEEM_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["STEEM_VOTE_DUST_THRESHOLD"] = STEEM_VOTE_DUST_THRESHOLD;
   result["STEEM_VOTING_MANA_REGENERATION_SECONDS"] = STEEM_VOTING_MANA_REGENERATION_SECONDS;
   result["STEEM_SYMBOL"] = STEEM_SYMBOL;
   result["VESTS_SYMBOL"] = VESTS_SYMBOL;
   result["STEEM_VIRTUAL_SCHEDULE_LAP_LENGTH"] = STEEM_VIRTUAL_SCHEDULE_LAP_LENGTH;
   result["STEEM_VIRTUAL_SCHEDULE_LAP_LENGTH2"] = STEEM_VIRTUAL_SCHEDULE_LAP_LENGTH2;
   result["STEEM_MAX_LIMIT_ORDER_EXPIRATION"] = STEEM_MAX_LIMIT_ORDER_EXPIRATION;
   result["STEEM_DELEGATION_RETURN_PERIOD_HF0"] = STEEM_DELEGATION_RETURN_PERIOD_HF0;
   result["STEEM_DELEGATION_RETURN_PERIOD_HF20"] = STEEM_DELEGATION_RETURN_PERIOD_HF20;
   result["STEEM_RD_MIN_DECAY_BITS"] = STEEM_RD_MIN_DECAY_BITS;
   result["STEEM_RD_MAX_DECAY_BITS"] = STEEM_RD_MAX_DECAY_BITS;
   result["STEEM_RD_DECAY_DENOM_SHIFT"] = STEEM_RD_DECAY_DENOM_SHIFT;
   result["STEEM_RD_MAX_POOL_BITS"] = STEEM_RD_MAX_POOL_BITS;
   result["STEEM_RD_MAX_BUDGET_1"] = STEEM_RD_MAX_BUDGET_1;
   result["STEEM_RD_MAX_BUDGET_2"] = STEEM_RD_MAX_BUDGET_2;
   result["STEEM_RD_MAX_BUDGET_3"] = STEEM_RD_MAX_BUDGET_3;
   result["STEEM_RD_MAX_BUDGET"] = STEEM_RD_MAX_BUDGET;
   result["STEEM_RD_MIN_DECAY"] = STEEM_RD_MIN_DECAY;
   result["STEEM_RD_MIN_BUDGET"] = STEEM_RD_MIN_BUDGET;
   result["STEEM_RD_MAX_DECAY"] = STEEM_RD_MAX_DECAY;
   result["STEEM_ACCOUNT_SUBSIDY_PRECISION"] = STEEM_ACCOUNT_SUBSIDY_PRECISION;
   result["STEEM_WITNESS_SUBSIDY_BUDGET_PERCENT"] = STEEM_WITNESS_SUBSIDY_BUDGET_PERCENT;
   result["STEEM_WITNESS_SUBSIDY_DECAY_PERCENT"] = STEEM_WITNESS_SUBSIDY_DECAY_PERCENT;
   result["STEEM_DEFAULT_ACCOUNT_SUBSIDY_DECAY"] = STEEM_DEFAULT_ACCOUNT_SUBSIDY_DECAY;
   result["STEEM_DEFAULT_ACCOUNT_SUBSIDY_BUDGET"] = STEEM_DEFAULT_ACCOUNT_SUBSIDY_BUDGET;
   result["STEEM_DECAY_BACKSTOP_PERCENT"] = STEEM_DECAY_BACKSTOP_PERCENT;
   result["STEEM_BLOCK_GENERATION_POSTPONED_TX_LIMIT"] = STEEM_BLOCK_GENERATION_POSTPONED_TX_LIMIT;
   result["STEEM_PENDING_TRANSACTION_EXECUTION_LIMIT"] = STEEM_PENDING_TRANSACTION_EXECUTION_LIMIT;

   return result;
}

} } // steem::protocol
