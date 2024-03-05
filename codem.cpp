namespace Magnum { namespace Audio { namespace Implementation {

static_assert(sizeof(RiffChunk) == 8, "RiffChunk size is not 8 bytes");
static_assert(sizeof(WavHeaderChunk) == 12, "WavHeaderChunk size is not 12 bytes");
static_assert(sizeof(WavFormatChunk) == 24, "WavFormatChunk size is not 24 bytes");

Debug& operator<<(Debug& debug, const WavAudioFormat value) {
    debug << "Audio::WavAudioFormat" << Debug::nospace;

     if(std::strncmp(currChunk->chunkId, "fmt ", 4) == 0) {
            if(formatChunk) {
                Error() << "Audio::WavImporter::openData(): the file contains too many format chunks";
                return;
            }

            formatChunk = WavFormatChunk{*reinterpret_cast<const WavFormatChunk*>(currChunk)};

        } else if(std::strncmp(currChunk->chunkId, "data", 4) == 0) {
            if(dataChunk != nullptr) {
                Error() << "Audio::WavImporter::openData(): the file contains too many data chunks";
                return;
            }
//hello
   if(hasBigEndianData != Utility::Endianness::isBigEndian())
        Utility::Endianness::swapInPlace(
            formatChunk->chunk.chunkSize, formatChunk->audioFormat,
            formatChunk->numChannels, formatChunk->sampleRate,
            formatChunk->byteRate, formatChunk->blockAlign,
            formatChunk->bitsPerSample);
