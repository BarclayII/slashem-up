/*	  SCCS Id: @(#)necro.c	3.2	 98/Oct/30		*/
/*	  Copyright (c) M. Stephenson 1988						  */
/* NetHack may be freely redistributed.  See license for details. */

#include "hack.h"

#define NECRO_PERFORMER	 ((u.ualign.type == A_CHAOTIC) && \
			  (Role_if(PM_NECROMANCER) || \
			   Role_if(PM_WIZARD) || \
			   Role_if(PM_FLAME_MAGE) || \
			   Role_if(PM_ICE_MAGE)))

int ud_dwarf[] = {PM_GHOUL, PM_GHAST, PM_WIGHT, PM_WRAITH, PM_GHOST, PM_GUG,
		  NON_PM};
int ud_gnome[] = {PM_GHOUL, PM_GHAST, PM_GHOST, PM_GHOUL_MAGE, PM_BARROW_WIGHT,
		  PM_WIGHT, PM_WRAITH, NON_PM};
int ud_human[] = {PM_GHOUL, PM_GHAST, PM_WRAITH, PM_GHOUL_MAGE, PM_VAMPIRE,
		  PM_GHOST, NON_PM};
int ud_orc[]   = {PM_GHOUL, PM_GHAST, PM_WIGHT, PM_WRAITH, PM_GHOST, PM_GUG,
		  PM_GHOUL_MAGE, NON_PM};
int ud_hbbt[]  = {PM_BARROW_WIGHT, PM_WIGHT, PM_WRAITH, PM_GHOST, NON_PM};
int ud_elf[]   = {PM_WRAITH, PM_GHOST, NON_PM};
int ud_ettin[] = {PM_GHOUL, PM_GHAST, PM_GUG, PM_WRAITH, PM_GHOST, NON_PM};
#define ud_giant ud_ettin
int ud_troll[] = {PM_GUG, PM_WRAITH, PM_GHOST, PM_WIGHT, NON_PM};
int ud_gnoll[] = {PM_WIGHT, PM_WRAITH, PM_GHOST, PM_GHOUL_MAGE, PM_GUG, NON_PM};
int ud_kbld[]  = {PM_GHOUL, PM_GHAST, PM_BARROW_WIGHT, PM_WIGHT, PM_GHOUL_MAGE,
		  PM_GHOST, NON_PM};
int ud_ogre[]  = {PM_GUG, PM_GHOUL_MAGE, PM_WRAITH, PM_GHOST, NON_PM};
int ud_cent[]  = {PM_WRAITH, PM_WIGHT, PM_GUG, PM_GHOST, NON_PM};
int ud_deep[]  = {PM_GUG, NON_PM};

int
random_pick_mon(monlist)
int monlist[];
{
	int i;
	for (i = 0; monlist[i] != NON_PM; ++i);
	return (i == 0) ? NON_PM : monlist[rn2(i)];
}

/*
 * raise undead
 */
int
raise_undead(obj)
struct obj *obj;
{
	if (!NECRO_PERFORMER)
		return NON_PM;
	int corpsenm, i, mlet;
	int pm_undead = NON_PM;
	int necro = Role_if(PM_NECROMANCER);
	/* check if the corpse is really a corpse */
	if (!obj && !rn2(15))
		return rn2(3) ? PM_SHADOW : PM_SHADE;
	if (!obj || obj->otyp != CORPSE)
		return NON_PM;
	/* check if the corpse is a humanoid corpse */
	corpsenm = obj->corpsenm;
	if (!humanoid(&mons[corpsenm])) return NON_PM;
	if (is_undead(&mons[corpsenm]))
		return corpsenm;
	if (obj->oxlth && obj->oattached != OATTACHED_MONST) {
		/* raise from a former undead corpse */
		struct monst *mnew = get_mtraits(obj, FALSE);
		if (is_undead(mnew->data))
			for (i = NON_PM; i < NUMMONS; ++i)
				if (mnew->data == &mons[i]) 
					return i;
	}
	/* 1 in 8 chance of creating a skeleton, regardless of monster type */
	if (!rn2(8))
		pm_undead = PM_SKELETON;
	else {
		/* non-necromancers often raise zombies */
		if (!necro && rn2(2))
			return mon_to_zombie(corpsenm);

		/* various monster flags */
		int dwarf = is_dwarf(&mons[corpsenm]);
		int gnome = is_gnome(&mons[corpsenm]);
		int human = is_human(&mons[corpsenm]);
		int orc = is_orc(&mons[corpsenm]);
		int hobbit = is_hobbit(&mons[corpsenm]);
		int elf = is_elf(&mons[corpsenm]);
		int ettin = (corpsenm == PM_ETTIN);
		int giant = (is_giant(&mons[corpsenm]) && !ettin);
		int troll = (mons[corpsenm].mlet == S_TROLL);
		int gnoll = (corpsenm == PM_GNOLL ||
			     corpsenm == PM_GNOLL_WARRIOR ||
			     corpsenm == PM_GNOLL_CHIEFTAIN ||
			     corpsenm == PM_GNOLL_SHAMAN);
		int kobold = (mons[corpsenm].mlet == S_KOBOLD);
		int ogre = (mons[corpsenm].mlet == S_OGRE);
		int centaur = (mons[corpsenm].mlet == S_CENTAUR);
		int deep = (corpsenm == PM_DEEP_ONE ||
			    corpsenm == PM_DEEPER_ONE ||
			    corpsenm == PM_DEEPEST_ONE);

		if (rn2(2)) {
			if (dwarf)
				pm_undead = PM_DWARF_MUMMY;
			else if (gnome)
				pm_undead = PM_GNOME_MUMMY;
			else if (human)
				pm_undead = PM_HUMAN_MUMMY;
			else if (orc)
				pm_undead = PM_ORC_MUMMY;
			else if (elf)
				pm_undead = PM_ELF_MUMMY;
			else if (kobold)
				pm_undead = PM_KOBOLD_MUMMY;
			else if (ettin)
				pm_undead = PM_ETTIN_MUMMY;
			else if (giant)
				pm_undead = PM_GIANT_MUMMY;
			else if (troll)
				pm_undead = PM_TROLL_MUMMY;
		}
		if (pm_undead == -1) {
			int *arr = 0;
			if (dwarf) arr = ud_dwarf;
			else if (gnome) arr = ud_gnome;
			else if (human) arr = ud_human;
			else if (orc) arr = ud_orc;
			else if (elf) arr = ud_elf;
			else if (hobbit) arr = ud_hbbt;
			else if (ettin) arr = ud_ettin;
			else if (giant) arr = ud_giant;
			else if (troll) arr = ud_troll;
			else if (gnoll) arr = ud_gnoll;
			else if (kobold) arr = ud_kbld;
			else if (ogre) arr = ud_ogre;
			else if (centaur) arr = ud_cent;
			else if (deep) arr = ud_deep;
			if (arr) pm_undead = random_pick_mon(arr);
		}
	}
	return pm_undead;
}
