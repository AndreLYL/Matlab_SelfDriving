function Fields = DrawRasterMap(rows,cols,startsub,endsub,obssub)
%DRAWRASTERMAO 绘制随机障碍物的栅格图,存在一个返回内容；输入格式（行数 列数 起点行列 终点行列置 障碍物行列）；
                                                       % 输出内容:数值化的栅格矩阵

% 定义栅格地图全域，并初始化空白区域
field = ones(rows, cols); %初始化空白区域 数值全为1,数值用于表示Cmap的颜色(因为Cmap数组索引只能从1开始)

% 起始点和目标点
start = startsub;                       % 起点的位置
goal = endsub;                          % 终点的位置
field(start(1),start(2)) = 4;           % 起点在数组的数值,数值用于表示Cmap的颜色
field(goal(1),goal(2)) = 5;             % 终点在数组的数值,数值用于表示Cmap的颜色

% 障碍物区域
obs = obssub;
field(obs(:,1),obs(:,2)) = 2;       %障碍物在数组的数值,数值用于表示Cmap的颜色

% ObsR = obssub(:,1);ObsC = obssub(:,2);
% obs = sub2ind([rows,cols],ObsR,ObsC);
% field(obs) = 2;                         % 障碍物在数组的数值,数值用于表示Cmap的颜色

% 函数返回值为数值化的栅格矩阵
Fields = field;

%构建数组的栅格图 可以查看帮助 help image
cmap = [1 1 1; ...       % 1-白色-空地
        0 0 0; ...       % 2-黑色-静态障碍
        1 0 0; ...       % 3-红色-动态障碍
        1 1 0;...        % 4-黄色-起始点 
        1 0 1;...        % 5-品红-目标点
        0 1 0; ...       % 6-绿色-到目标点的规划路径   
        0 1 1; ...       % 7-青色-动态规划的路径
        0 0 1];          % 8-蓝色

% 构建颜色MAP图
colormap(cmap);


% 绘制图像
image(1.5,1.5,field);
grid on;
set(gca,'gridline','-','gridcolor','k','linewidth',2,'GridAlpha',0.5);
set(gca,'xtick',1:cols+1,'ytick',1:rows+1);
set(gca, 'XAxisLocation','top')
axis image;

end
