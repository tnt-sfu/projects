
clc
clear
close all

%import csv file as a matrix;
matrix = csvread("10.csv",3);

%change matrix to read data in col 4
matrix = matrix(:,4);

%Find the average colour values in a window
windowSize = 3;
for i = 1:length(matrix)-(windowSize-1)
    matrixAvg(i) = sum(colourVals(i:i+(windowSize-1)))/windowSize;
end

%Find the derivative of each point in the avg
for i = 1:length(matrixAvg)-1
    avgDer(i) = matrixAvg(i+1)-matrixAvg(i);
end

%Plot everything above in 2 graphs and find the peaks of derivative
figure
subplot(2,1,1), plot(matrix); hold on;
subplot(2,1,1),plot(matrixAvg,'r'); hold on;
subplot(2,1,2), plot(avgDer); hold on;
findpeaks(abs(avgDer),'MinPeakHeight',2);
[~,locs]=findpeaks(abs(avgDer),'MinPeakHeight',6);

%Determine the width of the barcode based on the distances between peaks
%0 for short and 1 for long and save them into binary vector
i=1;
index=1;
binary = [0 0 0 0];
while i < length(locs) 
    if locs(i+1)-locs(i)>5
        binary(index)=1;
    else
        binary(index)=0;
    end
    i=i+2;
    index=inedx+1;
end

%convert elements in vector into string
binaryString = num2str(binary);

%flip to bin
binString = flip(binaryString);

%Output the number
output = bin2dec(binString);
fprintf("The barcode is for the number: %d \n", output);