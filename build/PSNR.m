nFrames = 1;      %# The number of frames
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

 [PY, PU, PV]=yuv_compare('forman_output_QP_Default.yuv','foreman_cif.yuv',[352 288]);
hold on;
