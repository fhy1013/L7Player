#pragma once

#include "core_decoder.h"

typedef std::function<void(int width, int height)> VideoCallback;

class CoreDecoderVideo : public CoreDecoder {
public:
    CoreDecoderVideo();

    ~CoreDecoderVideo() override;

    bool init(AVFormatContext* format_context, int stream_index, VideoCallback cb,
              std::shared_ptr<FrameQueue>& video_frame_queue);

    void unInit() override;

    bool decode(AVPacket* pack, DecodeCallback cb) override;

private:
    // void saveFramAsYUV(AVFrame* pFrame);
};