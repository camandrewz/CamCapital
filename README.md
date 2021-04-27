# CamCapital
Personal Project that implements a variety of HFT strategies in C++

This is still very much a work in progress. I hope to continue development into the future, adding more strategies, perhaps a dashboard of some kind, and importantly, the ability to trade via the FIX protocol.

Exchange: FTX.us

Resources Used:
- High-frequency trading in a limit order book (Marco Avellaneda & Sasha Stoikov) (https://people.orie.cornell.edu/sfs33/LimitOrderBook.pdf)
- Optimal High-Frequency Market Making (Takahiro Fushimi, Christian Gonz ́alez Rojas, & Molly Herman) (http://stanford.edu/class/msande448/2018/Final/Reports/gr5.pdf)
- https://www.reddit.com/r/highfreqtrading
- https://www.reddit.com/r/algotrading
- https://docs.ftx.us
- https://fix8.org


******************************************************************************************************************************************************************


Example of Pseudo-Market-Making (BCH/USD)... without actually trading... and if there was 0 latency... and takers for all my orders:
- This is using realtime data from FTX using a websocket, and conducting realtime analysis to determine profitable trades.

<p align="center">
  <img src="https://user-images.githubusercontent.com/20567677/116160523-351da900-a6c0-11eb-81c1-e87e7a5ea992.gif">
</p>
