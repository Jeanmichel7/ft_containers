/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:30:03 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/22 11:46:06 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHRONO_HPP__
# define __CHRONO_HPP__

#include <time.h>
#include <cstdio>
#include "main.hpp"

// struct timespec {
//         time_t   tv_sec;        /* seconds */
//         long     tv_nsec;       /* nanoseconds */
// };



struct time_diff
	{
		struct timespec stl_start;
		struct timespec stl_stop;
		struct timespec ft_start;
		struct timespec ft_stop;
		double stl_time;
		double ft_time;

		/* stl chrono */
		void stl_start_chrono() {
			if (clock_gettime(CLOCK_REALTIME, &stl_start) == -1) {
				perror("clock gettime start");
				exit(EXIT_FAILURE);
			}
		}

    double stl_end_chrono() {
      if (clock_gettime(CLOCK_REALTIME, &stl_stop) == -1) {
				perror("clock gettime end");
				exit(EXIT_FAILURE);
			}
      stl_time = (stl_stop.tv_sec - stl_start.tv_sec) 
						+	(double)(stl_stop.tv_nsec - stl_start.tv_nsec) 
						/ (double)BILLION;
      return stl_time;
    }

		double stl_get_chrono() {
			return stl_time;
		}

		void stl_display_chrono() {
      std::cout << fixed;
			std::cout << stl_time << "sec";
		}

		/* ft chrono */
		void ft_start_chrono() {
			if (clock_gettime(CLOCK_REALTIME, &ft_start) == -1) {
				perror("clock gettime start");
				exit(EXIT_FAILURE);
			}
		}

    double ft_end_chrono() {
      if (clock_gettime(CLOCK_REALTIME, &ft_stop) == -1) {
				perror("clock gettime end");
				exit(EXIT_FAILURE);
			}
      ft_time = (ft_stop.tv_sec - ft_start.tv_sec) 
						+	(double)(ft_stop.tv_nsec - ft_start.tv_nsec) 
						/ (double)BILLION;
      return ft_time;
    }

		double ft_get_chrono() {
			return ft_time;
		}

		void ft_display_chrono() {
      std::cout << fixed;
			std::cout << ft_time << "sec";
		}


		/* diff chrono */
		void diff_chrono() {
			std::cout << fixed;
			// std::cout << "STL chrono : " << stl_time << "sec" << std::endl;
			// std::cout << "FT chrono : " << ft_time << "sec" << std::endl;

			if (ft_time / 20 > stl_time) {
				std::cout << RED "\n[Time KO] " END << std::endl;
				std::cout << "STL chrono : " << stl_time << "sec" << std::endl;
				std::cout << "FT chrono : " << ft_time << "sec" << std::endl;
			}
			else 
				std::cout << GRN "[Time OK] " END ;
			}

	};

#endif