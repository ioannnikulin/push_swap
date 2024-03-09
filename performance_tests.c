/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin  yb        #+#    #+#             */
/*   Updated: 2024/03/09 20:41:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "sort_turk_internal.h"
#define START 0 
#define SZ 135

typedef struct s_testcase {
	char *in;
	int	eff_cap;
}	t_testcase;

static void	populate(t_testcase *t);

void	performance_tests()
{
	int		res;
	FILE	*fs;
	char	rdbuf[30];
	char	callbuf[3000];
	int		callbuflen;

	t_testcase t[SZ];
	populate(t);
	printf("Starting %d sorting performance tests.\n", SZ - START);
	for (int i = START; i < SZ; i ++) {
		if ((CUR_DEBUG & OP_TEST_BORDER) > 0)
			printf("\n################################################################\n\n");
		if ((CUR_DEBUG & OP_TEST_NUMBERS) > 0)
			printf("test #%i\n", i);
		remove("stdout.txt");
		bzero(callbuf, 3000);
		strcat(strcat(strcat(callbuf, "ARG=\""), t[i].in), "\"; ./push_swap $ARG ");
		callbuflen = strlen(callbuf);
		strcat(callbuf, "| wc -l > stdout.txt");
		system(callbuf);
		fs = fopen("stdout.txt", "r");
		fscanf(fs, "%i", &res);
		if ((CUR_DEBUG & OP_TEST_FULLDETAILS) > 0)
			printf("got: %i, expected max: %i\n", res, t[i].eff_cap);
		assert(res <= t[i].eff_cap);
		fclose(fs);
		remove("stdout.txt");
		callbuf[callbuflen] = 0;
		strcat(callbuf, "| ./checker_linux $ARG > stdout.txt");
		system(callbuf);
		fs = fopen("stdout.txt", "r");
		fscanf(fs, "%s", rdbuf);
		assert(rdbuf[0] == 'O' && rdbuf[1] == 'K');
		fclose(fs);
	}
	remove("stdout.txt");
	printf("SUCCESS: all operations performed as predicted\n");
}


static void	populate(t_testcase *t)
{
	t[0]=(t_testcase){"1 2 3 4 5", 0};
	t[1]=(t_testcase){"1 2 3 5 4", 12};
	t[2]=(t_testcase){"1 2 4 3 5", 12};
	t[3]=(t_testcase){"1 2 4 5 3", 12};
	t[4]=(t_testcase){"1 2 5 3 4", 12};
	t[5]=(t_testcase){"1 2 5 4 3", 12};
	t[6]=(t_testcase){"1 3 2 4 5", 12};
	t[7]=(t_testcase){"1 3 2 5 4", 12};
	t[8]=(t_testcase){"1 3 4 2 5", 12};
	t[9]=(t_testcase){"1 3 4 5 2", 12};
	t[10]=(t_testcase){"1 3 5 2 4", 12};
	t[11]=(t_testcase){"1 3 5 4 2", 12};
	t[12]=(t_testcase){"1 4 2 3 5", 12};
	t[13]=(t_testcase){"1 4 2 5 3", 12};
	t[14]=(t_testcase){"1 4 3 2 5", 12};
	t[15]=(t_testcase){"1 4 3 5 2", 12};
	t[16]=(t_testcase){"1 4 5 2 3", 12};
	t[17]=(t_testcase){"1 4 5 3 2", 12};
	t[18]=(t_testcase){"1 5 2 3 4", 12};
	t[19]=(t_testcase){"1 5 2 4 3", 12};
	t[20]=(t_testcase){"1 5 3 2 4", 12};
	t[21]=(t_testcase){"1 5 3 4 2", 12};
	t[22]=(t_testcase){"1 5 4 2 3", 12};
	t[23]=(t_testcase){"1 5 4 3 2", 12};
	t[24]=(t_testcase){"2 1 3 4 5", 12};
	t[25]=(t_testcase){"2 1 3 5 4", 12};
	t[26]=(t_testcase){"2 1 4 3 5", 12};
	t[27]=(t_testcase){"2 1 4 5 3", 12};
	t[28]=(t_testcase){"2 1 5 3 4", 12};
	t[29]=(t_testcase){"2 1 5 4 3", 12};
	t[30]=(t_testcase){"2 3 1 4 5", 12};
	t[31]=(t_testcase){"2 3 1 5 4", 12};
	t[32]=(t_testcase){"2 3 4 1 5", 12};
	t[33]=(t_testcase){"2 3 4 5 1", 12};
	t[34]=(t_testcase){"2 3 5 1 4", 12};
	t[35]=(t_testcase){"2 3 5 4 1", 12};
	t[36]=(t_testcase){"2 4 1 3 5", 12};
	t[37]=(t_testcase){"2 4 1 5 3", 12};
	t[38]=(t_testcase){"2 4 3 1 5", 12};
	t[39]=(t_testcase){"2 4 3 5 1", 12};
	t[40]=(t_testcase){"2 4 5 1 3", 12};
	t[41]=(t_testcase){"2 4 5 3 1", 12};
	t[42]=(t_testcase){"2 5 1 3 4", 12};
	t[43]=(t_testcase){"2 5 1 4 3", 12};
	t[44]=(t_testcase){"2 5 3 1 4", 12};
	t[45]=(t_testcase){"2 5 3 4 1", 12};
	t[46]=(t_testcase){"2 5 4 1 3", 12};
	t[47]=(t_testcase){"2 5 4 3 1", 12};
	t[48]=(t_testcase){"3 1 2 4 5", 12};
	t[49]=(t_testcase){"3 1 2 5 4", 12};
	t[50]=(t_testcase){"3 1 4 2 5", 12};
	t[51]=(t_testcase){"3 1 4 5 2", 12};
	t[52]=(t_testcase){"3 1 5 2 4", 12};
	t[53]=(t_testcase){"3 1 5 4 2", 12};
	t[54]=(t_testcase){"3 2 1 4 5", 12};
	t[55]=(t_testcase){"3 2 1 5 4", 12};
	t[56]=(t_testcase){"3 2 4 1 5", 12};
	t[57]=(t_testcase){"3 2 4 5 1", 12};
	t[58]=(t_testcase){"3 2 5 1 4", 12};
	t[59]=(t_testcase){"3 2 5 4 1", 12};
	t[60]=(t_testcase){"3 4 1 2 5", 12};
	t[61]=(t_testcase){"3 4 1 5 2", 12};
	t[62]=(t_testcase){"3 4 2 1 5", 12};
	t[63]=(t_testcase){"3 4 2 5 1", 12};
	t[64]=(t_testcase){"3 4 5 1 2", 12};
	t[65]=(t_testcase){"3 4 5 2 1", 12};
	t[66]=(t_testcase){"3 5 1 2 4", 12};
	t[67]=(t_testcase){"3 5 1 4 2", 12};
	t[68]=(t_testcase){"3 5 2 1 4", 12};
	t[69]=(t_testcase){"3 5 2 4 1", 12};
	t[70]=(t_testcase){"3 5 4 1 2", 12};
	t[71]=(t_testcase){"3 5 4 2 1", 12};
	t[72]=(t_testcase){"4 1 2 3 5", 12};
	t[73]=(t_testcase){"4 1 2 5 3", 12};
	t[74]=(t_testcase){"4 1 3 2 5", 12};
	t[75]=(t_testcase){"4 1 3 5 2", 12};
	t[76]=(t_testcase){"4 1 5 2 3", 12};
	t[77]=(t_testcase){"4 1 5 3 2", 12};
	t[78]=(t_testcase){"4 2 1 3 5", 12};
	t[79]=(t_testcase){"4 2 1 5 3", 12};
	t[80]=(t_testcase){"4 2 3 1 5", 12};
	t[81]=(t_testcase){"4 2 3 5 1", 12};
	t[82]=(t_testcase){"4 2 5 1 3", 12};
	t[83]=(t_testcase){"4 2 5 3 1", 12};
	t[84]=(t_testcase){"4 3 1 2 5", 12};
	t[85]=(t_testcase){"4 3 1 5 2", 12};
	t[86]=(t_testcase){"4 3 2 1 5", 12};
	t[87]=(t_testcase){"4 3 2 5 1", 12};
	t[88]=(t_testcase){"4 3 5 1 2", 12};
	t[89]=(t_testcase){"4 3 5 2 1", 12};
	t[90]=(t_testcase){"4 5 1 2 3", 12};
	t[91]=(t_testcase){"4 5 1 3 2", 12};
	t[92]=(t_testcase){"4 5 2 1 3", 12};
	t[93]=(t_testcase){"4 5 2 3 1", 12};
	t[94]=(t_testcase){"4 5 3 1 2", 12};
	t[95]=(t_testcase){"4 5 3 2 1", 12};
	t[96]=(t_testcase){"5 1 2 3 4", 12};
	t[97]=(t_testcase){"5 1 2 4 3", 12};
	t[98]=(t_testcase){"5 1 3 2 4", 12};
	t[99]=(t_testcase){"5 1 3 4 2", 12};
	t[100]=(t_testcase){"5 1 4 2 3", 12};
	t[101]=(t_testcase){"5 1 4 3 2", 12};
	t[102]=(t_testcase){"5 2 1 3 4", 12};
	t[103]=(t_testcase){"5 2 1 4 3", 12};
	t[104]=(t_testcase){"5 2 3 1 4", 12};
	t[105]=(t_testcase){"5 2 3 4 1", 12};
	t[106]=(t_testcase){"5 2 4 1 3", 12};
	t[107]=(t_testcase){"5 2 4 3 1", 12};
	t[108]=(t_testcase){"5 3 1 2 4", 12};
	t[109]=(t_testcase){"5 3 1 4 2", 12};
	t[110]=(t_testcase){"5 3 2 1 4", 12};
	t[111]=(t_testcase){"5 3 2 4 1", 12};
	t[112]=(t_testcase){"5 3 4 1 2", 12};
	t[113]=(t_testcase){"5 3 4 2 1", 12};
	t[114]=(t_testcase){"5 4 1 2 3", 12};
	t[115]=(t_testcase){"5 4 1 3 2", 12};
	t[116]=(t_testcase){"5 4 2 1 3", 12};
	t[117]=(t_testcase){"5 4 2 3 1", 12};
	t[118]=(t_testcase){"5 4 3 1 2", 12};
	t[119]=(t_testcase){"5 4 3 2 1", 12};
	t[120]=(t_testcase){"48 -33 62 68 -30 42 -31 94 -45 -15 93 3 17 53 98 -13 36 16 18 -96 0 52 -83 7 -49 95 -36 -59 28 59 30 -90 -74 43 -93 -10 -17 84 96 12 69 -57 78 -37 6 -51 -85 -44 -52 -69 -24 54 66 21 61 -40 65 13 -55 -76 8 -99 -27 73 -95 -60 56 -19 50 37 15 85 -98 -75 -79 67 89 71 32 -92 -23 -22 -94 81 92 74 -84 2 31 34 -12 -81 47 26 -53 -86 -9 72 87 -71", 700};
	t[121]=(t_testcase){"55 -97 -13 27 -69 -96 91 80 21 -25 -16 -98 68 -77 4 -2 -7 50 14 26 2 35 62 5 45 30 11 93 -12 -26 -3 -92 -19 -54 -86 38 -73 -85 59 -36 8 79 -30 -40 -72 -18 77 -87 100 32 -82 57 -75 20 -11 -23 -53 -6 28 -68 -67 1 -62 90 -76 -41 33 74 -79 64 48 -31 41 -20 10 97 6 -39 -65 -93 53 -46 25 39 -55 85 22 -59 72 18 -90 60 -21 -22 29 98 -80 94 -78 89", 700};
	t[122]=(t_testcase){"-30 11 44 -47 -22 3 -96 48 -50 47 25 -16 9 -54 99 -85 41 39 -58 73 -97 -17 -90 21 -87 -73 -57 -69 -10 33 79 81 26 -29 -36 0 -49 15 -89 -32 36 -92 -33 4 -64 -43 -13 -77 42 -88 58 59 -100 62 -18 -82 -63 -91 78 71 -9 -21 97 30 29 90 52 -31 -67 16 -3 88 23 28 49 40 -79 63 -15 -84 77 -56 93 98 66 -45 50 -1 -55 92 -12 -24 100 17 -35 5 -81 22 -48 -62", 700};
	t[123]=(t_testcase){"49 -63 47 -59 -10 -38 -35 26 98 40 -27 -68 -96 100 62 -75 61 -62 -41 -6 -4 -97 55 19 -94 -14 -58 0 76 -36 75 -43 45 -67 51 90 38 -72 -71 65 32 -32 -61 -18 -51 -81 93 -29 -2 96 -70 58 84 -8 34 6 -56 48 94 -65 -52 97 44 1 -25 -93 71 -48 -92 99 11 78 -44 56 -23 -42 -13 54 81 -15 89 16 21 -79 -45 -33 88 -78 14 -28 25 -31 -89 -98 59 28 -21 -5 82 -82", 700};
	t[124]=(t_testcase){"-69 32 -19 -64 9 83 69 61 76 66 -77 98 46 43 -40 -56 56 22 34 -53 -89 72 1 2 -21 37 -65 -3 75 78 55 27 -32 -54 -71 82 73 70 -15 -39 -93 -88 -72 13 -34 -96 96 -8 -92 -6 -33 -41 16 23 -11 87 -55 79 63 100 14 45 -81 -16 86 -7 49 -94 28 -5 -91 -90 -78 -25 38 90 -45 35 -23 94 -60 81 21 65 -73 -80 19 60 91 10 84 17 -37 -26 20 -44 31 -17 -9 -74", 700};
	t[125]=(t_testcase){"187 1000 651 22 892 531 -881 -287 -489 847 -567 395 661 545 934 426 -609 -465 722 -521 -842 748 194 676 744 846 552 -764 -217 -826 -1 164 -121 191 54 -549 -951 -36 -657 -733 72 -341 871 -607 534 305 -830 -311 -828 -879 874 387 -935 -659 286 -885 858 205 759 405 149 -745 -537 806 801 475 -993 637 -515 -380 -471 122 -291 -271 -54 -108 -18 574 -837 -835 -330 279 -338 -529 516 918 -547 -375 -595 419 428 781 -70 30 -710 -514 515 66 861 440 326 -480 -240 998 7 -997 37 593 -642 -26 -3 607 -136 -230 639 -97 756 -68 -524 807 -796 -464 -89 614 210 303 678 660 -80 25 510 -131 58 77 928 -863 -203 -784 -708 -972 -973 733 -98 95 -723 590 285 -392 875 348 523 -296 -47 75 -156 554 28 887 -284 925 878 -994 -562 -581 -747 259 126 -355 505 999 55 -196 357 -640 -249 -357 -286 -897 -780 50 390 -507 -724 547 -683 -168 834 658 -301 -597 -999 -527 -769 -522 905 -568 -343 -856 812 403 455 -257 -967 160 466 888 -689 417 973 996 908 -452 125 -913 -75 250 -572 -492 -762 566 220 -963 -896 -890 -957 926 494 39 -144 902 240 434 -366 -891 577 -847 115 -704 -475 777 588 549 369 404 415 -438 342 691 -115 -713 414 308 864 609 -234 -865 -530 -819 -715 615 512 -170 507 32 -532 -744 -459 218 580 -171 290 -329 -806 865 255 519 408 -741 561 56 -726 -626 -316 254 -5 65 -188 -180 82 517 331 474 -758 -798 851 -398 813 -362 725 213 80 293 612 -29 648 941 190 -593 500 47 -215 766 -430 602 269 -408 -482 289 -645 -852 -550 -360 -998 288 -403 -812 -456 495 438 165 -770 -559 294 379 988 168 112 350 116 -665 423 431 541 35 584 488 -541 197 447 134 -706 451 101 882 -22 -922 -443 792 207 730 727 837 -779 -232 309 -525 -300 -483 -395 699 810 564 -1000 -413 679 -807 454 490 497 15 -440 -213 146 -281 819 383 -389 654 435 539 469 -372 -936 -932 -198 -337 -768 -716 388 442 19 -225 -548 -91 -323 -320 -861 -754 -377 -169 738 971 -28 -485 -766 712 108 441 381 -838 -591 -577 -698 -33 485 -923 334 143 406 -520 721 -344 152 153 -694 140 982 -193 -511 -633 915 -614 965 260 93 68 -892 884 -774 -771 -916 592 863 -526 -285 967 118 778 -497 206 73 -274 225 -247 -229 429 949 -912 -191 508 -786 596 -259 -339 -728 -817 879 -126 -132 -960 -299 979 -560 374 942 -283 -725 -919 -466 -751 359 832 -669 581 -543 -382 339 295 411 -740", 5500};
	t[126]=(t_testcase){"835 -94 526 560 950 211 932 233 796 -335 -830 -615 -546 457 -736 -232 532 432 735 -641 228 107 812 -140 363 664 673 350 -476 801 82 159 520 -79 -64 -934 -349 936 -190 919 152 927 -650 999 403 -339 -396 -479 762 -398 410 -197 320 -417 -512 24 -819 834 358 -204 252 -548 -655 -706 -603 -229 -112 -712 908 -101 590 -1000 256 -559 -608 491 989 892 502 -62 -196 782 -983 -496 -245 967 727 2 -827 -146 987 -583 -804 140 616 301 273 -193 -779 -681 244 712 -509 -938 -625 460 551 -710 524 556 -393 -293 -216 124 116 -211 981 -980 421 992 595 -533 -707 704 -45 104 -517 -315 -585 160 -478 -824 726 -930 879 0 779 -984 740 200 -799 -595 -12 -791 -899 914 5 166 -873 -105 -59 814 696 -832 -334 811 -739 11 534 -189 -321 -306 -92 413 -466 -890 268 59 -375 169 -194 -969 527 -91 -117 91 74 -421 902 -716 492 -891 -37 947 332 412 33 -817 -71 -740 568 -846 917 -218 -433 -327 -618 523 -991 -840 -918 50 938 800 69 -987 272 46 594 394 719 566 53 -629 -181 442 -911 -156 671 250 853 900 357 -606 619 -649 -796 163 -792 -523 583 -653 -134 -88 849 173 -410 -365 -600 794 -491 -931 -923 880 382 -127 976 755 264 837 -66 -259 -265 367 -440 330 522 206 -384 -238 -113 99 -263 -541 404 -794 -833 171 770 438 945 882 223 -235 -246 -801 710 764 -471 424 -363 557 153 134 85 771 -376 562 -713 968 -458 535 -829 -351 -20 316 52 -872 466 572 698 -325 -853 -686 285 -673 -136 877 417 -270 -972 -754 789 625 158 -555 146 825 -106 338 43 648 -374 122 -47 -724 8 -124 -311 747 -341 767 -261 863 48 -480 -735 577 -968 529 506 -859 -73 -750 748 -562 467 -42 373 878 443 818 769 486 513 -462 -97 629 -477 -467 -996 -701 481 306 288 -268 -346 -391 -195 493 -995 -415 -929 862 -962 336 684 213 -319 42 893 325 -878 -137 991 40 -860 923 25 765 386 -84 833 -892 -348 -659 185 781 -13 35 846 489 -87 -954 621 -56 -358 -63 -416 307 -928 -114 375 13 -689 -35 235 -544 -831 -742 581 148 -515 -355 734 -513 997 207 38 -620 -342 -623 511 -647 -795 -670 407 60 817 -310 -746 -683 494 -74 355 -266 -53 -307 41 977 -177 582 -82 -77 985 -329 164 -575 142 183 806 281 -551 -294 -953 -881 -530 -337 -264 57 -836 -109 322 -244 -957 -688 3 -145 -359 -812 -708 -345 -336 -785 974 -699 -605 37 -975 21 -187 963 434 564 -103 -332 598 -894 -719 497", 5500};
	t[127]=(t_testcase){"-295 958 -970 -677 5 804 300 155 -858 -978 966 350 -975 -586 -451 267 -751 -767 309 142 -846 -71 460 675 -322 281 49 318 889 48 -102 547 207 127 472 -446 -455 -262 -926 -588 -429 32 -495 -490 -109 686 -256 64 998 -1000 41 745 607 -967 464 206 -635 483 482 -148 438 -473 658 -574 -188 209 748 -418 -467 -382 37 669 845 268 94 -91 461 -117 692 26 -231 -815 514 35 -691 114 390 211 862 863 -230 419 -889 -979 594 -77 -811 -972 -160 -405 534 776 859 190 263 -798 637 -842 399 395 -951 693 352 -41 302 -546 611 -390 923 -831 -985 -573 -526 -49 592 -899 512 79 -306 578 84 242 -690 -682 -67 723 836 -795 -4 172 -223 541 -661 441 620 -973 -226 -626 -699 275 714 757 851 825 -8 20 73 132 359 -553 976 -187 -240 -363 297 747 650 891 348 -263 -219 -812 47 588 -276 -778 -108 164 -839 -166 -13 722 435 277 -989 269 -84 -743 -205 -711 72 119 -38 628 341 531 331 -536 -151 480 -211 205 58 -685 -554 -824 -62 746 279 -624 -618 844 956 -734 52 455 573 -402 -90 -518 -762 -849 -928 -578 847 6 416 881 728 -892 -698 -895 -657 -777 166 929 -658 362 71 236 -935 -733 543 -634 679 -26 636 -441 446 781 -793 -281 -339 402 -125 453 434 -731 513 952 899 928 -710 -474 978 -791 -443 -184 -465 510 -144 727 -332 159 -438 -984 877 106 -409 865 519 -572 -932 -557 468 -321 787 -988 -180 -845 474 605 439 342 -217 623 270 -204 -19 -286 296 282 761 -529 639 915 -308 -619 -966 -239 -460 28 -156 599 -145 -191 -172 -161 -632 117 -623 -20 -252 603 46 -668 347 500 935 -571 103 916 -735 -930 152 957 -688 -316 944 587 -408 -258 -470 -356 -407 -986 346 194 -201 -314 -198 -135 173 -195 440 -753 838 754 868 648 -181 -268 -897 659 -357 798 445 -115 -227 -911 -869 -549 980 -773 -862 -761 -399 936 -78 -780 -993 213 -663 -269 -196 -832 -273 959 371 -247 349 -24 -427 -654 -550 -770 -14 557 83 -56 955 909 563 -11 -461 199 943 -178 418 469 565 -421 768 276 -602 707 -876 -621 -666 -379 -285 289 140 494 -203 293 875 602 -425 -423 702 -946 -645 -596 -539 -471 671 -870 -675 -1 880 -182 -948 660 -341 670 -522 794 -134 393 -224 651 118 695 -59 752 818 -105 -990 254 -300 305 969 -633 -589 312 274 -694 629 -347 -794 14 -81 893 -437 -436 24 647 -472 630 447 631 99 217 993 -913 625 -478 259 -597 805 -628 606 -535 356 979 -39 -312 449 815", 5500};
	t[128]=(t_testcase){"-365 -318 -377 52 -294 -216 53 -971 790 776 -761 337 -955 -360 -736 288 460 717 748 841 -399 -405 781 854 -266 970 -634 -882 -300 -472 -383 594 825 616 -771 421 530 -513 526 439 -522 -770 -490 -712 -500 606 582 741 540 -986 -697 -926 778 -19 61 551 74 411 279 -224 298 -875 745 668 -274 227 -834 316 823 -541 -883 -631 377 -358 932 -776 567 -458 791 -148 -515 -872 797 953 252 -312 143 -341 -338 652 49 151 -23 158 630 -351 -539 -210 -467 393 -993 241 -964 522 -935 941 134 -277 -226 578 -299 -218 122 -871 16 -673 -572 849 599 808 -878 -309 -92 -340 -586 -325 -127 677 -408 -297 -742 267 -526 -583 969 -654 -752 469 8 -691 -132 -30 597 -902 139 341 207 -853 982 -645 557 254 -379 464 31 -56 -590 -103 109 463 -713 -491 -791 960 -264 30 289 274 320 503 77 -256 170 734 235 -951 852 669 273 -721 -502 -923 -155 728 604 -423 -219 671 -525 489 -920 701 958 401 -370 -369 843 269 547 -716 562 -661 -514 87 -956 -554 -239 610 580 -681 -904 -576 -430 855 115 338 -518 44 -507 286 -54 42 -550 -163 774 335 136 -848 -908 569 583 438 915 -403 399 -429 -997 883 -24 -44 76 729 -702 -686 -455 65 255 -450 -669 135 -916 750 -460 869 167 -664 -921 -819 -190 445 675 -90 893 -110 -579 -974 200 -618 -182 -718 -613 278 943 101 -242 223 -724 468 343 349 287 -381 318 666 -704 -505 -744 -459 -248 552 653 234 -449 -268 -457 -605 474 -688 191 -512 531 565 333 177 -940 -469 895 -501 -677 -717 498 607 153 294 631 590 -856 147 -464 -660 -440 -655 655 -57 -867 809 -898 641 -36 441 121 -866 496 188 -973 -292 642 -969 215 863 326 -253 367 155 -154 201 690 -948 -910 203 827 -497 787 -296 -7 -480 228 -632 -611 -345 378 -894 -937 -275 450 -663 -524 -847 -313 291 908 -173 -143 371 176 -166 303 47 948 -22 -535 221 693 -203 -65 -114 457 -517 872 129 -723 618 -954 -433 -61 -808 591 718 -72 66 528 423 362 130 156 -205 862 -561 253 -917 -288 360 613 758 -34 -900 512 -758 -295 -546 173 957 -828 -999 955 163 369 753 -243 -825 494 601 -653 -600 257 -735 374 -281 755 -392 431 171 -499 980 -657 -803 978 -146 -746 -767 -800 -425 501 204 -731 -690 743 -136 506 355 210 -991 -305 700 -417 829 -636 -419 -125 -1 422 165 495 436 -170 988 -353 -406 -975 314 -599 976 358 -347 -466 -473 -80 -1000 -25 -870 661 710 -868 -152 410 -238 454 706 579 -12", 5500};
	t[129]=(t_testcase){"-533 -766 88 474 -792 245 -49 -913 -881 107 -796 208 -283 -775 -203 -287 -53 -799 -451 363 503 -280 -590 -816 -209 189 -188 232 421 -958 143 146 -942 -260 -742 -455 255 541 -103 957 69 -821 -912 -583 526 -672 -376 385 -520 394 257 -123 -658 399 154 858 -549 212 408 -471 567 555 -412 500 581 102 -147 -400 886 857 -272 112 100 32 -240 719 347 -175 118 331 -232 -995 -480 -621 -278 -106 669 261 -776 -434 -867 -425 608 -517 -783 123 538 657 -859 -662 14 311 -70 -536 -920 769 -382 744 953 517 -36 709 788 888 -317 960 -630 -786 -579 -811 631 -59 -347 -372 -795 -764 -653 70 -601 -254 -495 470 -242 185 869 -297 690 365 882 755 -265 374 -910 596 -67 -130 101 378 72 -481 352 628 -28 937 379 954 17 42 -711 -655 3 -756 -138 135 -977 -116 219 504 -737 169 -149 -812 710 26 -847 -616 -118 775 -24 -237 426 -858 940 906 -271 514 850 -276 464 692 863 711 936 -869 -296 -27 -498 642 -957 796 553 974 432 66 377 -896 -665 283 941 324 87 670 262 -524 151 519 49 47 826 164 375 237 -85 -952 -870 -235 -186 -883 -415 -69 417 4 168 463 -721 -304 -337 -388 864 -650 612 892 -944 -401 -638 972 -91 -636 -322 893 905 -256 -339 -151 381 721 899 46 667 445 -744 770 604 -566 979 -346 -419 321 -387 -946 475 -761 702 476 -644 -903 694 94 186 946 527 823 942 641 507 824 13 -351 830 -860 -880 406 -840 931 -671 648 -236 -543 -230 -986 703 844 248 372 301 -608 -368 325 889 -748 822 -421 319 -898 756 529 -206 -781 260 -360 414 -564 609 454 707 682 -478 587 559 68 211 105 -557 -784 605 618 -114 494 466 793 911 -488 235 965 -484 836 -865 949 -904 405 531 -746 784 -3 -990 -819 -670 61 -540 -956 140 -493 -497 -724 521 276 144 -365 -541 -159 562 342 -657 440 640 722 701 -197 778 922 -81 -727 -26 448 -363 166 231 -950 419 547 -635 717 369 -710 -341 -713 -573 366 818 142 724 -545 -307 880 592 -42 -820 909 -215 84 176 -939 292 357 994 -316 -17 827 524 699 688 124 175 -487 330 680 97 -891 525 738 -393 -395 -758 -596 -54 40 45 -290 535 -40 459 780 99 -356 -179 -765 -442 -359 -996 -225 22 -470 -855 -57 -852 720 578 161 392 747 -261 -38 80 -443 480 310 647 -323 346 -450 865 306 -121 376 595 -603 809 -615 268 735 -886 111 764 -534 -862 -994 171 731 59 932 64 -126 145 750 -268 -357 -18 887 897 -375", 5500};
	t[130]=(t_testcase){"737 711 600 978 -838 989 -58 468 -67 -777 320 -90 988 -68 634 -418 -700 -534 560 703 -415 -936 -518 904 -508 -712 86 502 -202 -244 -327 169 -575 -675 699 -839 -845 484 758 -474 38 639 318 963 -150 266 500 696 -378 386 296 384 -682 -590 729 127 -352 627 -776 -107 402 -576 418 -370 217 586 -687 488 -651 -877 -659 -349 -618 252 -31 581 -624 219 419 859 272 -926 -167 892 742 -439 -881 17 436 -16 -86 920 648 -380 196 872 -514 187 251 -544 -589 313 449 850 840 72 -266 864 -602 -250 -285 -527 -29 590 870 779 713 -318 -310 -966 868 692 -3 799 931 204 939 -585 -601 -773 915 -920 427 473 655 -374 564 31 723 925 -989 -669 980 -284 -909 -361 674 -287 863 -536 -797 -274 585 873 744 382 94 -939 -69 -546 205 -410 -362 33 620 -640 704 -45 -169 594 -665 -530 371 -136 849 -319 637 -180 941 -114 -286 98 928 -656 2 -964 -816 717 -401 170 135 -612 -516 -446 420 -276 32 200 -835 12 -732 182 -449 -363 515 -230 13 622 -613 -75 463 -563 -541 282 -225 710 607 794 87 479 -924 268 347 -524 -911 831 134 -84 -692 494 -398 -49 117 100 80 -186 -104 321 -210 550 311 178 -707 662 -456 689 474 -333 884 167 -893 -454 -382 968 720 462 -591 970 -10 679 -52 -819 -393 -556 860 -1000 -735 848 470 259 -567 265 -442 -815 763 -785 -428 -173 918 -172 954 -729 -137 -88 764 -828 493 278 784 528 766 569 664 258 486 -810 -737 798 -978 183 -887 822 333 -57 -896 819 -212 695 -900 -623 630 391 -670 174 -740 471 267 -723 -763 670 747 -578 -915 -539 -642 37 572 -600 -235 461 871 -48 -443 562 445 -467 721 -273 -322 389 328 392 -616 701 891 647 173 257 -343 -323 151 -923 448 706 511 395 -980 -927 964 -856 829 -554 580 261 360 789 -215 782 0 229 -485 -484 428 603 -416 882 -694 -949 -98 260 160 578 759 -696 -411 367 530 526 740 559 -495 337 -919 858 -663 631 -800 -519 -792 -511 -259 930 -109 -840 416 -795 277 557 736 264 256 521 -141 -607 896 947 901 -237 804 -709 -190 482 685 -568 -81 -462 -721 576 -782 -505 690 -771 698 -364 96 280 -383 423 -156 -510 -409 806 974 -56 497 -908 -874 -718 -708 -317 129 985 -638 95 177 396 90 -412 164 358 -572 -849 -801 189 -328 -762 809 -691 -451 59 -33 124 956 -455 722 370 -146 439 675 855 -269 -399 -553 -463 -260 -38 -110 -11 -195 898 908 817 838 236 606 -155 -34 498 633 -85", 5500};
	t[131]=(t_testcase){"737 711 600 978 -838 989 -58 468 -67 -777 320 -90 988 -68 634 -418 -700 -534 560 703 -415 -936 -518 904 -508 -712 86 502 -202 -244 -327 169 -575 -675 699 -839 -845 484 758 -474 38 639 318 963 -150 266 500 696 -378 386 296 384 -682 -590 729 127 -352 627 -776 -107 402 -576 418 -370 217 586 -687 488 -651 -877 -659 -349 -618 252 -31 581 -624 219 419 859 272 -926 -167 892 742 -439 -881 17 436 -16 -86 920 648 -380 196 872 -514 187 251 -544 -589 313 449 850 840 72 -266 864 -602 -250 -285 -527 -29 590 870 779 713 -318 -310 -966 868 692 -3 799 931 204 939 -585 -601 -773 915 -920 427 473 655 -374 564 31 723 925 -989 -669 980 -284 -909 -361 674 -287 863 -536 -797 -274 585 873 744 382 94 -939 -69 -546 205 -410 -362 33 620 -640 704 -45 -169 594 -665 -530 371 -136 849 -319 637 -180 941 -114 -286 98 928 -656 2 -964 -816 717 -401 170 135 -612 -516 -446 420 -276 32 200 -835 12 -732 182 -449 -363 515 -230 13 622 -613 -75 463 -563 -541 282 -225 710 607 794 87 479 -924 268 347 -524 -911 831 134 -84 -692 494 -398 -49 117 100 80 -186 -104 321 -210 550 311 178 -707 662 -456 689 474 -333 884 167 -893 -454 -382 968 720 462 -591 970 -10 679 -52 -819 -393 -556 860 -1000 -735 848 470 259 -567 265 -442 -815 763 -785 -428 -173 918 -172 954 -729 -137 -88 764 -828 493 278 784 528 766 569 664 258 486 -810 -737 798 -978 183 -887 822 333 -57 -896 819 -212 695 -900 -623 630 391 -670 174 -740 471 267 -723 -763 670 747 -578 -915 -539 -642 37 572 -600 -235 461 871 -48 -443 562 445 -467 721 -273 -322 389 328 392 -616 701 891 647 173 257 -343 -323 151 -923 448 706 511 395 -980 -927 964 -856 829 -554 580 261 360 789 -215 782 0 229 -485 -484 428 603 -416 882 -694 -949 -98 260 160 578 759 -696 -411 367 530 526 740 559 -495 337 -919 858 -663 631 -800 -519 -792 -511 -259 930 -109 -840 416 -795 277 557 736 264 256 521 -141 -607 896 947 901 -237 804 -709 -190 482 685 -568 -81 -462 -721 576 -782 -505 690 -771 698 -364 96 280 -383 423 -156 -510 -409 806 974 -56 497 -908 -874 -718 -708 -317 129 985 -638 95 177 396 90 -412 164 358 -572 -849 -801 189 -328 -762 809 -691 -451 59 -33 124 956 -455 722 370 -146 439 675 855 -269 -399 -553 -463 -260 -38 -110 -11 -195 898 908 817 838 236 606 -155 -34 498 633 -85", 5500};
	t[132]=(t_testcase){"999 993 991 987 986 980 975 972 971 970 968 960 949 937 929 927 925 922 921 920 913 908 905 899 896 883 880 879 877 864 861 858 853 850 848 844 843 839 838 835 834 820 818 816 813 810 808 807 804 803 800 797 796 791 788 785 784 780 777 775 774 771 770 765 764 763 759 758 754 750 748 746 744 742 738 733 724 718 715 712 709 702 700 698 695 692 691 671 670 662 659 658 652 651 640 632 630 625 620 610 608 607 606 597 594 588 575 570 559 552 550 544 543 542 540 538 530 527 525 522 521 509 498 496 494 493 489 486 484 483 481 479 475 472 464 459 455 452 441 431 428 424 419 417 414 411 407 399 391 390 380 379 365 362 360 351 350 348 343 342 340 332 331 330 327 324 322 320 317 313 309 305 293 290 287 286 278 272 271 265 262 260 254 252 251 249 243 240 237 236 234 229 226 225 221 216 212 209 205 199 191 190 187 186 175 166 165 164 163 157 155 148 141 137 125 121 114 113 107 106 102 99 97 96 90 84 83 75 69 67 66 65 62 61 54 52 44 40 31 30 28 15 14 10 6 5 1 0 -10 -12 -13 -17 -23 -25 -27 -29 -32 -33 -35 -42 -45 -47 -49 -68 -69 -73 -74 -76 -78 -82 -86 -90 -93 -98 -99 -101 -119 -122 -124 -125 -131 -132 -147 -148 -153 -155 -157 -159 -163 -166 -169 -170 -172 -177 -178 -181 -186 -188 -193 -199 -203 -205 -216 -231 -237 -238 -239 -242 -243 -244 -245 -246 -254 -255 -256 -258 -260 -266 -269 -271 -281 -283 -286 -292 -301 -302 -311 -314 -316 -341 -346 -361 -364 -368 -370 -371 -372 -374 -378 -379 -380 -383 -384 -387 -388 -399 -400 -401 -408 -409 -418 -420 -421 -424 -434 -435 -437 -446 -449 -450 -459 -460 -461 -463 -465 -469 -475 -479 -480 -489 -493 -503 -507 -511 -514 -517 -520 -530 -533 -535 -549 -550 -552 -554 -556 -558 -563 -565 -571 -574 -576 -577 -582 -585 -586 -588 -589 -590 -592 -594 -600 -607 -615 -626 -627 -628 -629 -634 -637 -638 -639 -647 -648 -652 -656 -661 -662 -670 -671 -675 -677 -678 -679 -682 -698 -699 -702 -709 -722 -724 -726 -728 -731 -732 -741 -743 -744 -745 -753 -755 -756 -759 -761 -763 -771 -773 -775 -776 -779 -783 -786 -798 -799 -802 -806 -811 -819 -825 -829 -830 -836 -837 -839 -840 -843 -847 -850 -854 -863 -868 -875 -876 -881 -890 -892 -901 -906 -908 -909 -921 -927 -928 -929 -933 -938 -939 -940 -949 -958 -961 -966 -970 -972 -976 -986 -987 -990 -992 -997 -999", 5500};
	t[133]=(t_testcase){"-999 -997 -992 -990 -987 -986 -976 -972 -970 -966 -961 -958 -949 -940 -939 -938 -933 -929 -928 -927 -921 -909 -908 -906 -901 -892 -890 -881 -876 -875 -868 -863 -854 -850 -847 -843 -840 -839 -837 -836 -830 -829 -825 -819 -811 -806 -802 -799 -798 -786 -783 -779 -776 -775 -773 -771 -763 -761 -759 -756 -755 -753 -745 -744 -743 -741 -732 -731 -728 -726 -724 -722 -709 -702 -699 -698 -682 -679 -678 -677 -675 -671 -670 -662 -661 -656 -652 -648 -647 -639 -638 -637 -634 -629 -628 -627 -626 -615 -607 -600 -594 -592 -590 -589 -588 -586 -585 -582 -577 -576 -574 -571 -565 -563 -558 -556 -554 -552 -550 -549 -535 -533 -530 -520 -517 -514 -511 -507 -503 -493 -489 -480 -479 -475 -469 -465 -463 -461 -460 -459 -450 -449 -446 -437 -435 -434 -424 -421 -420 -418 -409 -408 -401 -400 -399 -388 -387 -384 -383 -380 -379 -378 -374 -372 -371 -370 -368 -364 -361 -346 -341 -316 -314 -311 -302 -301 -292 -286 -283 -281 -271 -269 -266 -260 -258 -256 -255 -254 -246 -245 -244 -243 -242 -239 -238 -237 -231 -216 -205 -203 -199 -193 -188 -186 -181 -178 -177 -172 -170 -169 -166 -163 -159 -157 -155 -153 -148 -147 -132 -131 -125 -124 -122 -119 -101 -99 -98 -93 -90 -86 -82 -78 -76 -74 -73 -69 -68 -49 -47 -45 -42 -35 -33 -32 -29 -27 -25 -23 -17 -13 -12 -10 0 1 5 6 10 14 15 28 30 31 40 44 52 54 61 62 65 66 67 69 75 83 84 90 96 97 99 102 106 107 113 114 121 125 137 141 148 155 157 163 164 165 166 175 186 187 190 191 199 205 209 212 216 221 225 226 229 234 236 237 240 243 249 251 252 254 260 262 265 271 272 278 286 287 290 293 305 309 313 317 320 322 324 327 330 331 332 340 342 343 348 350 351 360 362 365 379 380 390 391 399 407 411 414 417 419 424 428 431 441 452 455 459 464 472 475 479 481 483 484 486 489 493 494 496 498 509 521 522 525 527 530 538 540 542 543 544 550 552 559 570 575 588 594 597 606 607 608 610 620 625 630 632 640 651 652 658 659 662 670 671 691 692 695 698 700 702 709 712 715 718 724 733 738 742 744 746 748 750 754 758 759 763 764 765 770 771 774 775 777 780 784 785 788 791 796 797 800 803 804 807 808 810 813 816 818 820 834 835 838 839 843 844 848 850 853 858 861 864 877 879 880 883 896 899 905 908 913 920 921 922 925 927 929 937 949 960 968 970 971 972 975 980 986 987 991 993 999", 0};
	t[134]=(t_testcase){"-783 -779 -776 -775 -773 -771 -763 -761 -759 -756 -755 -753 -745 -744 -743 -741 -732 -731 -728 -726 -724 -722 -709 -702 -699 -698 -682 -679 -678 -677 -675 -671 -670 -662 -661 -656 -652 -648 -647 -639 -638 -637 -634 -629 -628 -627 -626 -615 -607 -600 -594 -592 -590 -589 -588 -586 -585 -582 -577 -576 -574 -571 -565 -563 -558 -556 -554 -552 -550 -549 -535 -533 -530 -520 -517 -514 -511 -507 -503 -493 -489 -480 -479 -475 -469 -465 -463 -461 -460 -459 -450 -449 -446 -437 -435 -434 -424 -421 -420 -418 -409 -408 -401 -400 -399 -388 -387 -384 -383 -380 -379 -378 -374 -372 -371 -370 -368 -364 -361 -346 -341 -316 -314 -311 -302 -301 -292 -286 -283 -281 -271 -269 -266 -260 -258 -256 -255 -254 -246 -245 -244 -243 -242 -239 -238 -237 -231 -216 -205 -203 -199 -193 -188 -186 -181 -178 -177 -172 -170 -169 -166 -163 -159 -157 -155 -153 -148 -147 -132 -131 -125 -124 -122 -119 -101 -99 -98 -93 -90 -86 -82 -78 -76 -74 -73 -69 -68 -49 -47 -45 -42 -35 -33 -32 -29 -27 -25 -23 -17 -13 -12 -10 0 1 5 6 10 14 15 28 30 31 40 44 52 54 61 62 65 66 67 69 75 83 84 90 96 97 99 102 106 107 113 114 121 125 137 141 148 155 157 163 164 165 166 175 186 187 190 191 199 205 209 212 216 221 225 226 229 234 236 237 240 243 249 251 252 254 260 262 265 271 272 278 286 287 290 293 305 309 313 317 320 322 324 327 330 331 332 340 342 343 348 350 351 360 362 365 379 380 390 391 399 407 411 414 417 419 424 428 431 441 452 455 459 464 472 475 479 481 483 484 486 489 493 494 496 498 509 521 522 525 527 530 538 540 542 543 544 550 552 559 570 575 588 594 597 606 607 608 610 620 625 630 632 640 651 652 658 659 662 670 671 691 692 695 698 700 702 709 712 715 718 724 733 738 742 744 746 748 750 754 758 759 763 764 765 770 771 774 775 777 780 784 785 788 791 796 797 800 803 804 807 808 810 813 816 818 820 834 835 838 839 843 844 848 850 853 858 861 864 877 879 880 883 896 899 905 908 913 920 921 922 925 927 929 937 949 960 968 970 971 972 975 980 986 987 991 993 999 -999 -997 -992 -990 -987 -986 -976 -972 -970 -966 -961 -958 -949 -940 -939 -938 -933 -929 -928 -927 -921 -909 -908 -906 -901 -892 -890 -881 -876 -875 -868 -863 -854 -850 -847 -843 -840 -839 -837 -836 -830 -829 -825 -819 -811 -806 -802 -799 -798 -786", 5500};
}