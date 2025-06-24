% Number of cameras
numCameras = 2;

% Create webcam objects
cams = cell(1, numCameras);
for i = 1:numCameras
    cams{i} = webcam(i);
end

faceDetector = vision.CascadeObjectDetector();

videoPlayer = vision.VideoPlayer('Name', 'Face Count Detection');

while isOpen(videoPlayer)
 
    totalFaceCount = 0;
    frames = cell(1, numCameras);
    for i = 1:numCameras
        frames{i} = snapshot(cams{i});
    end
    
   
    for i = 1:numCameras
       
        grayFrame = rgb2gray(frames{i});


        bbox = step(faceDetector, grayFrame);


        detectedFrame = insertShape(frames{i}, 'Rectangle', bbox, 'LineWidth', 3);
        step(videoPlayer, detectedFrame);

   
        totalFaceCount = totalFaceCount + size(bbox, 1);
    end
    

    disp(['Total Number of Faces: ', num2str(totalFaceCount)]);
end


for i = 1:numCameras
    release(cams{i});
end
release(videoPlayer);
