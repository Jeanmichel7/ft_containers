/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:30:03 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/21 20:01:39 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHRONO_HPP__
# define __CHRONO_HPP__

#include <time.h>

#include "main.hpp"

// struct timespec {
//         time_t   tv_sec;        /* seconds */
//         long     tv_nsec;       /* nanoseconds */
// };



struct time_diff
	{
		struct timespec start;
		struct timespec stop;
		double accum;

		void start_chrono() {
			if (clock_gettime(CLOCK_REALTIME, &start) == -1) {
				perror("clock gettime start");
				exit(EXIT_FAILURE);
			}
		}

    double end_chrono() {
      if (clock_gettime(CLOCK_REALTIME, &stop) == -1) {
				perror("clock gettime end");
				exit(EXIT_FAILURE);
			}
      accum = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / (double)BILLION;
      return accum;
    }

		double get_chrono() {
			return accum;
		}

		void display_chrono() {
      std::cout << fixed;
			std::cout << accum << "sec";
		}
	};

#endif