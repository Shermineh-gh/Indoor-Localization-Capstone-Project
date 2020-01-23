/* -*- c++ -*- */
/*
 * Copyright 2014 Triet Vo-Huu <vohuudtr@ccs.neu.edu>
 *
 * Wireless Security Lab - College of Computer and Information Science
 * Northeastern University, Boston, MA 02115, USA.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_SWIFI_WIFI_CONV_SOFT_DECODER_IMPL_H
#define INCLUDED_SWIFI_WIFI_CONV_SOFT_DECODER_IMPL_H

#include <swifi/wifi_conv_soft_decoder.h>
#include <swifi/wifi_conv_1_2.h>

namespace gr {
  namespace swifi {

    class wifi_conv_soft_decoder_impl : public wifi_conv_soft_decoder
    {
     private:
      std::vector<float> d_buffer;
      int d_blocksize, d_codedblocksize, d_stopsize, d_nitems_stored;
      wifi_conv_1_2 code;
      std::vector<tag_t> d_stored_tags;

      void set_blocksize(int blocksize);
      void set_stopsize(int blocksize);

      void propagate_tags();
      void update_rate(const tag_t &tag);

      int dynamic_rate_work(int noutput_items, int ninput_items,
        const void* input, void* output);

     public:
      wifi_conv_soft_decoder_impl(const std::string &phy_tag_key);
      wifi_conv_soft_decoder_impl(int blocksize);

    };

  } // namespace swifi
} // namespace gr

#endif /* INCLUDED_SWIFI_WIFI_CONV_SOFT_DECODER_IMPL_H */

