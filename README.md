# UNNY ![UNNY Logo](https://unny.ccore.online/images/coins_custom/unny_45.png)<br> 

Unny Release Tree [![GitHub version](https://img.shields.io/badge/Version-1.4.1.0-brightgreen.svg)](https://github.com/unnycore-coin/Unny/releases/tag/v1.4.1.0)


What is UnnyCore (UNNY)?

UnnyCore is a peer-to-peer decentralized digital currency for ordinary people, easy to use and acquire. We’re pushing for blockchain mass adoption through education and charity. A sustainable and scalable solutions in the charity and educational sectors on the Blockchain. UnnyCore summarizes the best characteristics of digital currencies, which were issued earlier (Bitcoin, Dash,PIVX), such as: increased security, fast consensus mechanism, and increased decentralization achieved by requiring miners to prove the knowledge of the transaction data. The community has created a coin with faster transaction, more secure, masternode and low transaction fee.

UnnyCore is not just another cryptocurrency in the market. It has specific use cases in the
educational and charity sectors

UnnyCore is fork of Pivx, improved with some of the following features: 

- DNS hardcoded 
- Supersecure
- Consesus by masternode 
- POS 3.0. fixed
- Fast transactions featuring guaranteed zero confirmation transaction: Instantsend 
- Intregated BIP38, multisignature, blockexplorer, wallet repair and multisend functions in wallet
- Low transaction fee

Unnycore’s Use-cases:
- Help bloggers to get tip using UNNY. 
- Providing an online educational resources library for professional courses, writers and readers. 
- Provide Charity organizations with option to be supported by using UNNY.
- Convert your UNNY coin to ($) Dollar/ (£) Euro and use it UNNY for coin listing and any node hosting


The project is led by 12 members: (Telegram/Discord)

- @Cryptowaker: Team leader
- @CryptoExtrem: Social manager
- @saajan4: Communication lead
- @barjan0x: Communication Support
- @Wundef: Marketing developer
- @lanoes: Core developer
- @ZioFabry: Core developer
- @GreatDaneGH: Software developer
- @ennybelly: Blockchain/web developer
- @Alain#4172: Full-stack Software developer
- @SeunCrypton#7048: Graphics and Animation

UnnyCore Specifications:
- Coin Name: Unnycore
- Ticker: UNNY
- Type: POS + Masternode
- Block time 60 seconds
- Block size 3 MB
- Block Reward 10 UNNY and will be reducing
- Algorithm Quark (pow period end)
- Transaction confirmation: 16 blocks
- Min Stake: 6 hours
- Max Supply: 21 Million
- Swap Supply: 1 Million
- Premined amount: 240.000 UNNY (0.11% approx)
- Masternode Collateral: 15.000 UNNY
- Reward: 90% masternode, 10% POS

UnnyCore Rewards:

POS Rewards:
```
	     1> block <= 50.000:   2 UNNY
 	50.000> block  <= 100.000: 3 UNNY
        100.000> block <= 150.000: 4 UNNY
	150.000> block <= 200.000: 5 UNNY
	200.000> block <= 250.000: 6 UNNY
	250.000> block <= 300.000: 7 UNNY
	300.000> block <= 350.000: 8 UNNY
	350.000> block <= 400.000: 9 UNNY
	400.000> block <= 450.000: 10 UNNY
	450.000> block <= 500.000: 11 UNNY
	500.000> block <= 550.000: 12 UNNY
	550.000> block <= 600.000: 11 UNNY
	600.000> block <= 650.000: 10 UNNY
 	650.000> block <= 700.000: 9 UNNY
	700.000> block <= 750.000: 8 UNNY
	750.000> block <= 800.000: 7 UNNY
	800.000> block <= 850.000: 6 UNNY
	850.000> block <= 900.000: 5 UNNY
	900.000> block <= 950.000: 4 UNNY
	950.000> block: 2 UNNY
```

Masternode Governance: 

```
   	      0> block <= 200: 0.10% //Preparing last pow block
	    200> block <= 50.000:  0.70%
 	50.000> block  <= 100.000: 0.71%
        100.000> block <= 150.000: 0.73%
	150.000> block <= 200.000: 0.73%
	200.000> block <= 250.000: 0.74%
	250.000> block <= 300.000: 0.75%
	300.000> block <= 350.000: 0.76%
	350.000> block <= 400.000: 0.77%
	400.000> block <= 450.000: 0.78%
	450.000> block <= 500.000: 0.79%
	500.000> block <= 550.000: 0.80%
	550.000> block <= 600.000: 0.81%
	600.000> block <= 650.000: 0.82%
 	650.000> block <= 700.000: 0.83%
	700.000> block <= 750.000: 0.84%
	750.000> block <= 800.000: 0.85%
	800.000> block <= 850.000: 0.86%
	850.000> block <= 900.000: 0.87%
	900.000> block <= 950.000: 0.88%
	950.000> block:	0.90%

```
# Debian/Ubuntu Linux Daemon Build Instructions

```
git clone https://github.com/unnycore-coin/Unny.git
cd Unny
./autogen.sh
./configure --disable-tests
make -j2 (2 is must be changed for number os Cpus that have VPS)
cd src
strip unnycored unnycore-cli
./unnycored -daemon
```

# UNNY important links
```
Website: https://unnycore.org
Whitepaper: https://unnycore.org/wp-content/uploads/2019/11/Unnycore_Whitepaper_1.2.0.0.pdf
Block Explorer :  https://unny.ccore.online or  https://unnyexplorer.unnycore.org
Github : https://github.com/unnycore-coin/Unny
Bitcointalk ANN: #msg48756089" rel="noopener noreferrer" target="_blank">https://bitcointalk.org/index.php?topic=5086942.msg48756089#msg48756089
Telegram-English: https://t.me/UnnyCore_official
Telegram-Announcements: https://t.me/Unnycore_Announcement
Official Twitter: https://twitter.com/UnnyCore_coin
Facebook: https://www.facebook.com/UnnyCoreCoin
Discord: https://discord.gg/sze9AaV
Masternode guide: https://github.com/unnycore-coin/Unny-MN
Masternode Monitoring/Statistics: 1. https://mnrank.com/coin/UNNY/ 2. https://masternodes.biz/coindetail.php?c=UNNY
UnnyCore Coin Tracker: https://www.coingecko.com/en/coins/unnycore
```
