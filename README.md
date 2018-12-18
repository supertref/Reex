# Reex

ReeCore is a peer-to-peer decentralized digital currency for ordinary people, easy to use and acquire.

ReeCore is fork of Pivx, improved with some of the following features: 

- Segwit protocol applied: fast transaction aprox. 300 tx/s 
- DNS hardcoded 
- Supersecure
- Consesus by masternode 
- POS 3.0.
- Fast transactions featuring guaranteed zero confirmation transaction: Instantsend 
- Intregated BIP38, multisignature, blockexplorer, wallet repair and multisend functions in wallet
- Low transaction fee


The project is leaded by 5 members: (telegram)

- @Cryptowaker: Team leader
- @CryptoExtrem: Social manager
- @saajan4: Community leader
- @Wundef: Marketing developer
- @lanoes: Core developer

ReeCore Specifications:

- Type: POS + MASTERNODE
- Ticker: REEX
- Block time: 90 seconds
- Block size: 3 MB
- Transaction confirmation: 15 blocks
- Min Stake: 10 hours
- Max Supply: 21 Millions
- Swap Supply: 1 Million  
- Premined amount: 240.000 REEX (0.11% premined aprox)
- Masternode amount: 1.000 REEX


ReeCore Rewards:

POS Rewards:
```
	     1> block <= 50.000:   2 REEX
 	50.000> block  <= 100.000: 3 REEX
        100.000> block <= 150.000: 4 REEX
	150.000> block <= 200.000: 5 REEX
	200.000> block <= 250.000: 6 REEX
	250.000> block <= 300.000: 7 REEX
	300.000> block <= 350.000: 8 REEX
	350.000> block <= 400.000: 9 REEX
	400.000> block <= 450.000: 10 REEX
	450.000> block <= 500.000: 11 REEX
	500.000> block <= 550.000: 12 REEX
	550.000> block <= 600.000: 11 REEX
	600.000> block <= 650.000: 10 REEX
 	650.000> block <= 700.000: 9 REEX
	700.000> block <= 750.000: 8 REEX
	750.000> block <= 800.000: 7 REEX
	800.000> block <= 850.000: 6 REEX
	850.000> block <= 900.000: 5 REEX
	900.000> block <= 950.000: 4 REEX
	950.000> block: 2 REEX
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
Debian/Ubuntu Linux Daemon Build Instructions
```
git clone https://github.com/Hser2bio/Reex.git
cd Reex
./autogen.sh
./configure --disable-tests
make -j2 (2 is must be changed for number os Cpus that have VPS)
cd src
./reecoredd -daemon
