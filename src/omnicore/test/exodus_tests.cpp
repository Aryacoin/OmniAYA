#include <omnicore/omnicore.h>
#include <omnicore/rules.h>

#include <base58.h>
#include <chainparams.h>
#include <key_io.h>
#include <test/test_bitcoin.h>

#include <boost/test/unit_test.hpp>

#include <limits>

using namespace mastercore;

BOOST_FIXTURE_TEST_SUITE(omnicore_exodus_tests, BasicTestingSetup)

BOOST_AUTO_TEST_CASE(exodus_address_mainnet)
{
    BOOST_CHECK(CTxDestination(DecodeDestination("AexoDusyQfrYZnUfNWGwWLt2oKoviRSB38")) ==
                ExodusAddress());
    BOOST_CHECK(!(CTxDestination(DecodeDestination("1rDQWR9yZLJY7ciyghAaF7XKD9tGzQuP6")) ==
                ExodusAddress()));
}

BOOST_AUTO_TEST_CASE(exodus_address_testnet)
{
    SelectParams(CBaseChainParams::TESTNET);

    BOOST_CHECK(CTxDestination(DecodeDestination("mxodUSi96BfpyLhbwuDBWBhe3LftE2gxhC")) ==
                ExodusAddress());
    BOOST_CHECK(!(CTxDestination(DecodeDestination("moneyqMan7uh8FqdCA2BV5yZ8qVrc9ikLP")) ==
                ExodusAddress()));

    SelectParams(CBaseChainParams::MAIN);
}

BOOST_AUTO_TEST_CASE(exodus_address_regtest)
{
    SelectParams(CBaseChainParams::REGTEST);

    BOOST_CHECK(CTxDestination(DecodeDestination("n3kqQAekxpw4YcCP7B1iAaDqyeWNotkH9e")) ==
                ExodusAddress());
    BOOST_CHECK(!(CTxDestination(DecodeDestination("moneyqMan7uh8FqdCA2BV5yZ8qVrc9ikLP")) ==
                ExodusAddress()));

    SelectParams(CBaseChainParams::MAIN);
}

BOOST_AUTO_TEST_SUITE_END()
