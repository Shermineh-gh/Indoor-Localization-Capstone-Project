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

#ifndef INCLUDED_SWIFI_TX_TIME_TAG_ADDER_IMPL_H
#define INCLUDED_SWIFI_TX_TIME_TAG_ADDER_IMPL_H

#include <swifi/tx_time_tag_adder.h>

namespace gr {
  namespace swifi {

    class tx_time_tag_adder_impl : public tx_time_tag_adder
    {
     private:
      uint64_t d_full_secs;
      double d_frac_secs;
      long d_length;
      double d_cycle_time;
      double d_time_stamp;
      pmt::pmt_t d_tx_time;
      pmt::pmt_t d_tx_time_tag_key;
      pmt::pmt_t d_length_tag_key;

     public:
      tx_time_tag_adder_impl(const uint64_t full_secs,
                            const double frac_secs,
                            const std::string &length_tag_key,
                            const long length);
      ~tx_time_tag_adder_impl();

      // Where all the action really happens
      int work(int noutput_items,
          gr_vector_const_void_star &input_items,
          gr_vector_void_star &output_items);
    };

  } // namespace swifi
} // namespace gr

#endif /* INCLUDED_SWIFI_TX_TIME_TAG_ADDER_IMPL_H */

