/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:19:53 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/01 21:22:29 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	tester_vector();
	// tester_map(); 
	// tester_stack();
	// tester_set();

	std::cout << std::endl;
	return 0;
}



/*
	REGLEMENT FABLAB

	L'acces au FabLab se fait par l'adhesion au club DIY

	Les horaires d'ouvertures sont du lundi au vendredi 
	de 8h a 17h sans responsable
	de 17h a 22-23h avec responsable car pas de gerant
	horaire weekend ?

	Le soir l'acces n'est autorise que si un responsable est present
	Certaine machine ne sont utilisable qu'apres une formation (decoupe laser, CNC)

	Les responsables auront une formation sur ces machines pour superviser les membres du club.

	Des creneaux peuvent etre pris sur le site de la bidouille pour reserver des machines, 
	mais n'est pas obligatoire.

	Les membres ont obligation de s'inscrire sur le site de la bidouille (pour accepter les termes et conditions)

	La capacite du FabLab est de 7-8 personnes dont les gerants. 
	Il est donc conseiller de faire des groupes de 2-4 personnes dans la journee.

	L'utilisation de la decoupe laser et CNC est facturer a l'heure, (montant ?) 
	Les consommables tel que le filament 3D est a la charge des membres (cagnotte)
*/