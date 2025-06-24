while(1)
cam = webcam;
faceDetector = vision.CascadeObjectDetector();
videoPlayer = vision.VideoPlayer('Name', 'Face Count Detection');
frame = snapshot(cam);
grayFrame = rgb2gray(frame);
bbox = step(faceDetector, grayFrame);
detectedFrame = insertShape(frame, 'Rectangle', bbox, 'LineWidth', 3);
step(videoPlayer, detectedFrame);
faceCount = size(bbox, 1);
disp(['Number of faces: ', num2str(faceCount)]);
release(videoPlayer);
end