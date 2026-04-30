image=ones(720,1280);
hold on;
%Get user's input
prompt = "Enter Number between 1- 15: ";
x = input(prompt);
while(x < 0 || x > 15)
    prompt = "Invalid Input. Please enter it again";
    x = input(prompt);
end
%change number to binary
binStr = dec2bin(x);
binStr = ['0' binStr(1:end)];
binStr = ['0' binStr(1:end)];
binStr = ['0' binStr(1:end)];
%make barcode image based on the binary
if binStr(:,end-3) == '1'
   image(:,961:1210) = 0;
else
    image(:,961:1060) = 0;
end
if binStr(:,end-2) == '1'
    image(:,640:890) = 0;
else
    image(:,640:740) = 0;
end
if binStr(:,end-1) == '1'
    image(:,320:570) = 0;
else
    image(:,320:420) = 0;
end
if binStr(:,end) == '1'
    image(:,1:250) = 0;
else
    image(:,1:100) = 0;
end
%put noise into the barcode
image = imnoise(image, "gaussian");
%save the image
imwrite(image,"Barcode1.jpg");