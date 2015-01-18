clear all;
clc;
%nFrames = 1;      %# The number of frames
vidHeight = 352;  %# The image height
vidWidth = 288;   %# The image width
% %movYUV = loadFileYuv('foreman_cif.yuv',vidHeight,vidWidth,1:nFrames);  %# Read the yuvfile2frame
% AVIobj=VideoReader('forman_output_QP_Default.yuv');
% movAVI=read(AVIobj,1);%# Read the avifile2frame
% %[imIn,mapIn] =frame2im(movYUV(1));
% [imOu,mapOu] =frame2im(movAVI(1));
% imshow( imIn );
%forman_output_QP32_10fs.yuv
%[PY, PU, PV]=yuv_compare('foreman_cif.yuv','forman_output_QP32_10fs.yuv',[352 288]);
nFrames=seq_frames('forman_output_lossless_X128_256_Y128_256_5frame.yuv',[352 288]);
[PY, PU, PV]=yuv_compare('forman_output_lossless_X128_256_Y128_256_5frame.yuv','foreman_cif.yuv',[352 288]);
[PY1, PU1, PV1]=yuv_compare('forman_output_QP_Default.yuv','foreman_cif.yuv',[352 288]);
subplot(3,1,1);
plot(1:nFrames,PY,1:nFrames,PY1);
xlabel('frame ');
ylabel('PSNR ');
legend('after','before',-1); 
subplot(3,1,2);
plot(1:nFrames,PU,1:nFrames,PU1);
xlabel('frame ');
ylabel('PSNR ');
legend('after','before',-1); 
subplot(3,1,3);
plot(1:nFrames,PV,1:nFrames,PV1);
xlabel('frame ');
ylabel('PSNR ');
legend('after','before',-1); 
hold on;
