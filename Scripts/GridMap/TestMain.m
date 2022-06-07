
%%%% TestMain.m
%%%% 脚本文件 用于直接调用函数 熟悉概念
clc;
clear;
close all;
rows = 4;cols = 5;

[startpos(1),startpos(2)] = ind2sub([rows,cols],3);
[endpos(1),endpos(2)] = ind2sub([rows,cols],19);
[obspos(:,1),obspos(:,2)] = ind2sub([rows,cols],[10;11;12]);

field = DrawRasterMap(rows,cols,startpos,endpos,obspos);
field
% 如果出线障碍物信息在地图上显示不对
% 可能是在函数内的field(obsIndex(:,1),obsIndex(:,2)) = 2;产生错误
% 可以采用将行列转成线性索引即函数内该代码下面注释的内容