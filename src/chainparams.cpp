
// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017 The Reliance developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "bignum.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x"));

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    //1516926684, // * UNIX timestamp of last checkpoint block
    //0,          // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    //2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));

static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1740710,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        pchMessageStart[0] = 0x01;
        pchMessageStart[1] = 0xf3;
        pchMessageStart[2] = 0x02;
        pchMessageStart[3] = 0xa4;
        vAlertPubKey = ParseHex("");
        nDefaultPort = 43210;
        bnProofOfWorkLimit = ~uint256(0) >> 20;
        nSubsidyHalvingInterval = 0;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 20 * 60;
        nTargetSpacing = 2 * 60;
        nMaturity = 10;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 21000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 200;
        nModifierUpdateBlock = 1;

        //  nTime: 1531169926
        //  nNonce: 474276
        //  Hash: 00000d6274a0459bc63c3b7ad6c03614bed636e2c43e10b466c553d03bb56ecc
        //  hashMerkleRoot: d356f4e8178a28f1ad5f15738db447731b86ca1a9a620ff8358fa607252f2220
        const char* pszTimestamp = "reecore mainnet nov2018";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04f4a8143f86ad8ac63791fbbdb8e0b91a8da88c8c693a95f6c2c13c063ea790f7960b8025a9047a7bc671d5cfe707a2dd2e13b86182e1064a0eea7bf863636363") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1542907235;
        genesis.nBits = 0x1e0ffff0;  // 00000ffff0000000000000000000000000000000000000000000000000000000
        genesis.nNonce = 347336;
        hashGenesisBlock = genesis.GetHash();

        if (genesis.nNonce != 0) {
           assert(hashGenesisBlock == uint256("0x00000c1b8abb8755561c46ea298cf725c940ca71409f7024bc3ad82fdb1bdc7f"));
           assert(genesis.hashMerkleRoot == uint256("0x71db3668e0435a23f1222acfcc186b84699bc1f9da54dcbb3cff6bf04dbc04af"));
        }

        if (genesis.nNonce == 0) {
           for(genesis.nNonce == 0; genesis.GetHash() > bnProofOfWorkLimit; genesis.nNonce++){ } 
           printf("  nTime: %u\n", genesis.nTime);
           printf("  nNonce: %u\n", genesis.nNonce);
           printf("  Hash: %s\n", genesis.GetHash().ToString().c_str());
           printf("  hashMerkleRoot: %s\n", genesis.hashMerkleRoot.ToString().c_str());
        } 

        //vSeeds.push_back(CDNSSeedData("", ""));
          
          vSeeds.push_back(CDNSSeedData("173.249.1.107", "173.249.1.107"));  
          vSeeds.push_back(CDNSSeedData("35.227.52.152", "35.227.52.152"));
	      vSeeds.push_back(CDNSSeedData("35.237.239.30", "35.237.239.30"));
		  vSeeds.push_back(CDNSSeedData("35.237.108.125", "35.237.108.125"));
		  vSeeds.push_back(CDNSSeedData("104.196.132.52", "104.196.132.52"));
		  vSeeds.push_back(CDNSSeedData("35.196.93.191", "35.196.93.191"));
		  vSeeds.push_back(CDNSSeedData("35.231.132.149", "35.231.132.149"));
		  vSeeds.push_back(CDNSSeedData("35.228.129.243", "35.228.129.243"));

          
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 61);  // R
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 122); // r
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 189);     // +128
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0xde).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "04cc17389379a0e323f53ea504d38cd71f43dc22f597805fed33a51b05ced1a3ae0db84089985f351b3737721736a82f58c8bd529f79c8ffe57e922bda792146ab";
        strMasternodePoolDummyAddress = "SsJVWUkt6HtSCY2SaJ2akeyJUg8bg1hW3S";
        nStartMasternodePayments = genesis.nTime + (3600); // one week after genesis creation

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x14;
        pchMessageStart[1] = 0xec;
        pchMessageStart[2] = 0x52;
        pchMessageStart[3] = 0x1e;
        vAlertPubKey = ParseHex("04f4a8143f86ad8ac63791fbbdb8e0b91a8da88c8c693a95f6c2c13c063ea790f7960b8025a9047a7bc671d5cfe707a2dd2e13b8618");
        nDefaultPort = 15151;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Reliance: 1 day
        nTargetSpacing = 2 * 60;  // Reliance: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 1;
        nMaxMoneyOut = 21000000 * COIN;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1525777781;
        genesis.nNonce = 21451168;

        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x06b942b8b7f0e05ea38e7871a0db70f71592cfb016ee0ae7d5988f9fea840201"));

        vFixedSeeds.clear();
        vSeeds.clear();

        // Testnet Reliance addresses start with 's'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 48);
        // Testnet Reliance script addresses start with '5' or '6'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 12);
        // Testnet private keys start with 'k'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 108);
        // Testnet Reliance BIP32 pubkeys start with 'tpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        // Testnet Reliance BIP32 prvkeys start with 'tprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
        // Testnet bitcoin green BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04abb5e65280dda6a113fadfb9877f9c399532245fe1acb61de293ab298034d5084277fab3768774a3b68cbbe5021cc5049ec8c9997a13f64da1afa0bcfb156db1";
        strMasternodePoolDummyAddress = "SbJ4Qad4xc77PpLzMx6rUegAs6aUPWkcUq";
        nStartMasternodePayments = genesis.nTime + 86400; // 24 hours after genesis
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x14;
        pchMessageStart[1] = 0xec;
        pchMessageStart[2] = 0x52;
        pchMessageStart[3] = 0x1e;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // Reliance: 1 day
        nTargetSpacing = 2 * 60;        // Reliance: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1525777781;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 21451168;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 25151;
        //assert(hashGenesisBlock == uint256("0x06b942b8b7f0e05ea38e7871a0db70f71592cfb016ee0ae7d5988f9fea840201"));

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Regtest mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
