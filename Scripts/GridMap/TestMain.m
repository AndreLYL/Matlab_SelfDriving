
%%%% TestMain.m
%%%% �ű��ļ� ����ֱ�ӵ��ú��� ��Ϥ����
clc;
clear;
close all;
rows = 4;cols = 5;

[startpos(1),startpos(2)] = ind2sub([rows,cols],3);
[endpos(1),endpos(2)] = ind2sub([rows,cols],19);
[obspos(:,1),obspos(:,2)] = ind2sub([rows,cols],[10;11;12]);

field = DrawRasterMap(rows,cols,startpos,endpos,obspos);
field
% ��������ϰ�����Ϣ�ڵ�ͼ����ʾ����
% �������ں����ڵ�field(obsIndex(:,1),obsIndex(:,2)) = 2;��������
% ���Բ��ý�����ת�����������������ڸô�������ע�͵�����