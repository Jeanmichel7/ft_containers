/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:30:03 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/23 22:43:02 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHRONO_HPP__
# define __CHRONO_HPP__

#include <time.h>
#include <cstdio>
#include "main.hpp"
// #include <sys/time.h>
#include <iomanip>

// struct timespec {
//         time_t   tv_sec;        /* seconds */
//         long     tv_nsec;       /* nanoseconds */
// };


// int operation (int x, int y,int (*function)(int,int)){return function(x,y);}
// int operation2(int x, int y,std::function<int(int, int)> function){return function(x,y);}

// void time_diff( void (*function)(int,int), void (*function)(int,int)) {

// }

struct s_time_diff
	{
		struct timespec stl_start;
		struct timespec stl_stop;
		struct timespec ft_start;
		struct timespec ft_stop;
		double 					stl_time;
		double 					ft_time;
		double 					diff;
		int 						count;
		double 					sum;


		s_time_diff() : count(0), sum(0) {}

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
			stl_time == 0 ? diff = 0 : diff = ft_time / stl_time;

			if (ft_time / 20 > stl_time) {
				std::cout << RED "\n[TKO " << std::setprecision(2) << diff << "x] " END << std::endl;
				std::cout << "STL chrono : " << std::setprecision(6) << stl_time << "s" << std::endl;
				std::cout << "FT chrono  : " << std::setprecision(6) << ft_time << "s" << std::endl;
			}
			else if (ft_time / 10 > stl_time)
				std::cout << YEL "[TOK "<< std::setprecision(1) << diff << "x] " END ;
			else if (ft_time / 2 > stl_time)
				std::cout << CYA "[TOK "<< std::setprecision(1) << diff << "x] " END ;
			else
				std::cout << GRN "[TOK "<< std::setprecision(1) << diff << "x] " END ;
			
			if (stl_time != (double)0 ) {
				sum += diff;
				count++;
			}
		}

		void display_average() {
			std::cout << MAG "\n\nTEST performance" END << std::endl;
			std::cout << fixed;
			if (sum / count < 2)
				std::cout << GRN;
			else if (sum / count < 10)
				std::cout << CYA;
			else if (sum / count < 20)
				std::cout << RED;
			std::cout << "Average time : " << std::setprecision(3) << sum / count << "x less performant" END << std::endl;
		}
	};

#endif