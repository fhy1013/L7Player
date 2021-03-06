#pragma once

#include "core_decoder.h"
#include "swresample_proxy.h"

typedef std::function<bool(AudioParams in)> AudioCallback;

class CoreDecoderAudio : public CoreDecoder {
public:
    CoreDecoderAudio();

    ~CoreDecoderAudio() override;

    bool init(AVFormatContext* format_context, int stream_index, AudioCallback cb,
              std::shared_ptr<FrameQueue>& audio_frame_queue);

    void unInit() override;

    bool decode(AVPacket* pack, DecodeCallback cb) override;

private:
    bool pushFrame(AVFrame* frame);
};