#ifndef RAIDSTREAM_RAIDFILESTRIPE_HPP
#define RAIDSTREAM_RAIDFILESTRIPE_HPP

#include <memory>
#include <sole/sole.hpp>
#include "RaidStream/RaidFile.hpp"
#include "RaidStream/RaidFileBlock.hpp"

namespace RaidStream {
    enum RaidStripeType {
        SUPER,
        JBOD,
        RAID5,
        RAID6,
        EXPERIMENTAL
    };

    class RaidFileStripe {
    public:
        inline RaidFileStripe(std::shared_ptr<RaidFile> raidFile, const RaidStripeType type, std::vector<RaidFileBlock> blocks);

        inline const sole::uuid UUID();

    protected:
        std::shared_ptr<RaidFile> _raidFile = nullptr;
        const sole::uuid _uuid = sole::uuid4();
        const RaidStripeType _type;
        RaidFileBlock::block_size_t _blockSize;
        size_t _effectiveStripSize;
        RaidFile::raid_block_map _stripeBlocks;
    };
}

#endif //RAIDSTREAM_RAIDFILESTRIPE_HPP
