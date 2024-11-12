% invoke example program and store output in eekf.log
system('../../build/examples/eekf_example > ../../build/examples/eekf_example.txt');

% read eekf.log into D
D = readtable('eekf_example.txt');
M = table2array(D);
% plot data
subplot(3,1,1)
plot(M(:,[2 8 10]))
xlabel('k')
ylabel('position')
legend x p z;

subplot(3,1,2)
plot(M(:,[3 9]))
xlabel('k')
ylabel('velocity')
legend dx v;

subplot(3,1,3)
plot(M(:,10) - M(:,8), 'c'); hold on;
plot(M(:,2) - M(:,8), 'r'); hold off;
xlabel('k')
ylabel('error')
legend 'z - p' 'x - p';

