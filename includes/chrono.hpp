/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:30:03 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/01 21:33:53 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHRONO_HPP__
# define __CHRONO_HPP__

# include <time.h>
# include <cstdio>
# include <iomanip>
# include <cstdlib>


# include "main.hpp"

struct s_time_diff
	{
		struct timespec stl_start;
		struct timespec stl_stop;
		struct timespec ft_start;
		struct timespec ft_stop;
		double 					stl_time;
		double 					ft_time;
		double					stl_additionnal_time;
		double					ft_additionnal_time;
		double 					diff;
		int 						count;
		double 					sum;

		double get_stl_time(void) { return (this->stl_time); }
		double get_ft_time(void) 	{ return (this->ft_time); }
		double get_diff(void) 		{ return (this->diff); }
		double get_stl_additionnal_time(void) { return (this->stl_additionnal_time); }
		double get_ft_additionnal_time(void) { return (this->ft_additionnal_time); }


		s_time_diff() : stl_additionnal_time(0), ft_additionnal_time(0), count(0), sum(0){}

		/* ********** */
		/* STL chrono */
		/* ********** */

		void stl_start_chrono() {
			if (clock_gettime(CLOCK_REALTIME, &stl_start) == -1) {
				perror("clock gettime start");
				exit(EXIT_FAILURE);
			}
		}

		double stl_break_chrono() {
      if (clock_gettime(CLOCK_REALTIME, &stl_stop) == -1) {
				perror("clock gettime end");
				exit(EXIT_FAILURE);
			}
      stl_time = (stl_stop.tv_sec - stl_start.tv_sec) 
						+	(double)(stl_stop.tv_nsec - stl_start.tv_nsec) 
						/ (double)BILLION;
			// std::cout <<  std::setprecision(9) << "STL chrono: " << stl_time << "s" << std::endl;
			stl_additionnal_time += stl_time;
			// std::cout <<  std::setprecision(9) << "stl additionnal time: " << stl_additionnal_time << std::endl;
      return stl_additionnal_time;
    }

    double stl_end_chrono() {
			if (USE_CHRONO) {
				if (clock_gettime(CLOCK_REALTIME, &stl_stop) == -1) {
					perror("clock gettime end");
					exit(EXIT_FAILURE);
				}
				stl_time = (stl_stop.tv_sec - stl_start.tv_sec) 
							+	(double)(stl_stop.tv_nsec - stl_start.tv_nsec) 
							/ (double)BILLION;
				return stl_time;
			}
			return stl_break_chrono();
    }

		double stl_get_chrono() {
			return stl_time;
		}

		void stl_display_chrono() {
      std::cout << std::fixed;
			std::cout << stl_time << "sec";
		}





		/* *********** */
		/*  FT chrono  */
		/* *********** */

		void ft_start_chrono() {
			if (clock_gettime(CLOCK_REALTIME, &ft_start) == -1) {
				perror("clock gettime start");
				exit(EXIT_FAILURE);
			}
		}

		double ft_break_chrono() {
      if (clock_gettime(CLOCK_REALTIME, &ft_stop) == -1) {
				perror("clock gettime end");
				exit(EXIT_FAILURE);
			}
      ft_time = (ft_stop.tv_sec - ft_start.tv_sec) 
						+	(double)(ft_stop.tv_nsec - ft_start.tv_nsec) 
						/ (double)BILLION;
			ft_additionnal_time += ft_time;
      return ft_additionnal_time;
    }

    double ft_end_chrono() {
			if (USE_CHRONO) {
      	if (clock_gettime(CLOCK_REALTIME, &ft_stop) == -1) {
					perror("clock gettime end");
					exit(EXIT_FAILURE);
				}
      	ft_time = (ft_stop.tv_sec - ft_start.tv_sec) 
							+	(double)(ft_stop.tv_nsec - ft_start.tv_nsec) 
							/ (double)BILLION;
      	return ft_time;
			}
			return ft_break_chrono();
    }

		double ft_get_chrono() {
			return ft_time;
		}

		void ft_display_chrono() {
      std::cout << std::fixed;
			std::cout << ft_time << "sec";
		}





		/* ********** */
		/* DIFF Chrono */
		/* ********** */
		void diff_chrono() {
			if (stl_time >= 0.000001) {
				if (USE_CHRONO) {
					std::cout << std::fixed;
					stl_time == 0 ? diff = 0 : diff = ft_time / stl_time;

					if (ft_time / 20 > stl_time) {
						std::cout << RED "\n[TKO " << std::setprecision(2) << diff << "x] " END << std::endl;
						std::cout << "STL chrono : " << std::setprecision(8) << stl_time << "s" << std::endl;
						std::cout << "FT chrono  : " << std::setprecision(8) << ft_time << "s" << std::endl;
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
				else {
					diff_addition_chrono();
				}
			}
		}

		void diff_addition_chrono() {
			std::cout << std::fixed;
			// std::cout << std::setprecision(9) << "stl time : " << stl_additionnal_time << "\n ft_time : " 
			// 					<< ft_additionnal_time << std::endl;
			stl_additionnal_time == 0 ? diff = 0 : diff = ft_additionnal_time / stl_additionnal_time;

			if (ft_additionnal_time / 20 > stl_additionnal_time) {
				std::cout << RED "\n[TKO " << std::setprecision(2) << diff << "x] " END << std::endl;
				std::cout << "STL chrono : " << std::setprecision(8) << stl_additionnal_time << "s" << std::endl;
				std::cout << "FT chrono  : " << std::setprecision(8) << ft_additionnal_time << "s" << std::endl;
			}
			else if (ft_additionnal_time / 10 > stl_additionnal_time)
				std::cout << YEL "[TOK "<< std::setprecision(1) << diff << "x] " END ;
			else if (ft_additionnal_time / 2 > stl_additionnal_time)
				std::cout << CYA "[TOK "<< std::setprecision(1) << diff << "x] " END ;
			else
				std::cout << GRN "[TOK "<< std::setprecision(1) << diff << "x] " END ;
			
			if (stl_additionnal_time != (double)0 ) {
				sum += diff;
				count++;
			}
		}

		void display_average() {
			std::cout << MAG "\n\nTEST performance" END << std::endl;
			std::cout << std::fixed;
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