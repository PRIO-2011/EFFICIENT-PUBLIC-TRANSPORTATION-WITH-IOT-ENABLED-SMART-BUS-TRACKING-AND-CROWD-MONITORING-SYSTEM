cam = webcam;  % Initialize webcam once
faceDetector = vision.CascadeObjectDetector();
videoPlayer = vision.VideoPlayer('Name', 'Face Count Detection');

s = serial('COM5', 'BaudRate', 9600); % Initialize serial communication
fopen(s);

while true
    frame = snapshot(cam);
    grayFrame = rgb2gray(frame);
    bbox = step(faceDetector, grayFrame);
    detectedFrame = insertShape(frame, 'Rectangle', bbox, 'LineWidth', 3);
    step(videoPlayer, detectedFrame);
    
    faceCount = size(bbox, 1);
    disp(['Number of faces: ', num2str(faceCount)]);
    
    % Send corresponding serial data
    if faceCount == 1
        fwrite(s, 'AA');
    elseif faceCount == 2
        fwrite(s, 'BB');
    elseif faceCount == 3
        fwrite(s, 'CC');
    elseif faceCount >= 4
        fwrite(s, 'DD');
    end
    
    pause(2); % Adjust as necessary
    
    % Break condition (press a key to exit)
    if ~isempty(get(gcf, 'CurrentCharacter'))
        break;
    end
end

% Cleanup
fclose(s);
clear s;
release(videoPlayer);
clear cam;
