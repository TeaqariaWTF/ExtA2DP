#ifndef EXTA2DP_BLUETOOTH_A2DP_GLUE_H
#define EXTA2DP_BLUETOOTH_A2DP_GLUE_H
#include <unordered_map>
#include "bt_av.h"

extern int codec_indices[BTAV_A2DP_QVA_CODEC_INDEX_SOURCE_MAX];

extern const btav_source_interface_t glue_a2dp_interface;
extern const btav_source_interface_t *original_a2dp_interface;

static inline const char *codec_index_to_name(btav_a2dp_codec_index_t codec_type) {
    switch (codec_type) {
        case BTAV_A2DP_CODEC_INDEX_SOURCE_SBC:
            return "SBC";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_AAC:
            return "AAC";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX:
            return "aptX";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_HD:
            return "aptX HD";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_ADAPTIVE:
            return "aptX Adaptive";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_LDAC:
            return "LDAC";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_TWS:
            return "aptX TWS";
        case BTAV_A2DP_CODEC_INDEX_SINK_SBC:
            return "SBC (Sink)";
        case BTAV_A2DP_CODEC_INDEX_SINK_AAC:
            return "AAC (Sink)";
        case BTAV_A2DP_CODEC_INDEX_SINK_LDAC:
            return "LDAC (Sink)";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_LC3:
            return "LC3";
        case BTAV_A2DP_CODEC_INDEX_SINK_OPUS:
            return "Opus (Sink)";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_OPUS:
            return "Opus";
// Savitech Patch - START
        case BTAV_A2DP_CODEC_INDEX_SOURCE_LHDCV2:
            return "LHDC V2";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_LHDCV3:
            return "LHDC V3";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_LHDCV5:
            return "LHDC V5";
// Savitech Patch - END
        case BTAV_A2DP_CODEC_INDEX_SOURCE_FLAC:
            return "FLAC";
        case BTAV_A2DP_CODEC_INDEX_SOURCE_LC3PLUS_HR:
            return "LC3plus HR";
        case BTAV_A2DP_CODEC_INDEX_MAX:
            return "Unknown(CODEC_INDEX_MAX)";
    }
}

#endif //EXTA2DP_BLUETOOTH_A2DP_GLUE_H
