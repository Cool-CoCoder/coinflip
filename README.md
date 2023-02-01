# cppgame-randomGame

## 简介
命令行随机小游戏

1. 随机抛数枚硬币,程序会告诉你正反的数量.
2. 随机抛数枚骰子,程序会告诉你每个面出现的数量以及整体比率.
3. 俄罗斯轮盘赌,程序会打印每一轮幸存的玩家.

写这些程序的初衷其实也仅仅是为了实践随机数的应用,其实这些小游戏说穿了就是通过random()得到随机数然后取余得到想要的范围.
> 容易证明的是,设余数为a,在INT_MAX/a比较大时,取余后,余数范围内数字出现的概率基本是相同的.
> 可以用袋子中的小球数量来理解,例如袋子中有5种颜色不同小球,其数量分别为9999和9999,9998,9997,10000,我们能够认为从袋中抽出这5种小球的概率是相同的,也就是说我们能够接受一些细微的误差.

最后,如果大家有什么好玩的点子欢迎在Discussions中讨论.

## 使用方法
本项目没有makefile,如果感兴趣直接把源文件下载并编译后,找到GameCenter.cpp,利用main启动即可.

## 展示
```
Which game do you want to play?(give the number)
1.Tossing coins.
2.Rolling dices.
3.Roulette.
>1 // 另外两个可以自己探索
How many coins do you want to toss:(no more than INT_MAX)
>21312312

The number of times when the coin is head is:10654747
The number of times when the coin is tail is:10657566
The ratio of head is:0.499934
Do you want to play again?(Y/N)

```
