#ifndef MVTXFHR_MVTXPIXELMASK_H
#define MVTXFHR_MVTXPIXELMASK_H

#include "MvtxPixelDefs.h"

#include <ffarawobjects/MvtxRawHit.h>

#include <vector>
#include <climits>
#include <memory>


class MvtxPixelMask
{
    public:

        MvtxPixelMask(){}
        ~MvtxPixelMask(){ clear();}

        typedef std::vector<MvtxPixelDefs::pixelkey> hot_pixel_map_t;

        void load_from_CDB();

        void add_pixel(MvtxPixelDefs::pixelkey key);
        void remove_pixel(MvtxPixelDefs::pixelkey key);
        
        void clear();

        bool is_masked(MvtxRawHit* hit) const;

        hot_pixel_map_t get_hot_pixel_map() const { return m_hot_pixel_map; }

    private:

        hot_pixel_map_t m_hot_pixel_map {};

};

#endif // MVTXPIXELMASK_H
