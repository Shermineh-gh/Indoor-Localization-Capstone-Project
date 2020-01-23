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


#ifndef INCLUDED_SWIFI_BITMETRICS_INTERLEAVER_IMPL_H
#define INCLUDED_SWIFI_BITMETRICS_INTERLEAVER_IMPL_H

#include <swifi/bitmetrics_interleaver.h>

namespace gr {
  namespace swifi {

    class bitmetrics_interleaver_impl : public bitmetrics_interleaver
    {
     private:
      bool d_is_interleaver;
      std::vector<int> d_mapping;

      void update_rate(const tag_t &tag);

      int dynamic_rate_work(int noutput_items, int ninput_items,
        const void* input, void* output);

     public:
      bitmetrics_interleaver_impl(bool is_interleaver, const std::string &phy_tag_key);
      bitmetrics_interleaver_impl(bool is_interleaver, int rate);

      void set_interleaving_map(int rate);

    };

  } // namespace swifi
} // namespace gr

#endif /* INCLUDED_SWIFI_BITMETRICS_INTERLEAVER_IMPL_H */

