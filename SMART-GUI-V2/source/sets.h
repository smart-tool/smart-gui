/*
 * SMART: string matching algorithms research tool.
 * Copyright (C) 2012  Simone Faro and Thierry Lecroq
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 * 
 * contact the authors at: faro@dmi.unict.it, thierry.lecroq@univ-rouen.fr
 * download the tool at: http://www.dmi.unict.it/~faro/smart/
 */


int *PATT_SIZE;
int PATT_CUSTOM_SIZE[NumPatt];
int PATT_VERY_SHORT[NumPatt] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,0};
int PATT_SHORT_SIZE[NumPatt] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,0};
int PATT_LARGE_SIZE[NumPatt] = {2,4,8,16,32,64,128,256,512,1024,2048,4096,0,0,0,0,0};
char *SETTING_BUFFER[NumSetting] = {"rand2", "rand4", "rand8", "rand16", "rand32", "rand64", "rand128", "rand250", "italianTexts", "englishTexts", "frenchTexts", "chineseTexts", "midimusic", "genome", "protein"};
int  SETTING_ALPHA_SIZE[NumSetting]= {2,4,8,16,32,64,128,250,128,128,128,128,128,64,64};

int EXECUTE[NumAlgo];
char *ALGO_NAME[NumAlgo];
char *ALGO_DESCRIPTION[NumAlgo];

#include "function.h"

enum algo_pos {
//Comparison based Algorithms
_BF, 			//Brute Force
_MP, 			//Morris-Pratt
_KMP, 			//Knuth-Morris Pratt
_BM, 			//Boyer-Moore
_HOR, 			//Hoorspool
_GS, 			//Galil Seiferas
_AG, 			//Apostolico-Giancarlo
_KR, 			//Karp-Rabin
_ZT, 			//Zhu-Takaoka
_AC, 			//Apostolico-Crochemore
_TW, 			// Two-Way
_OM, 			//Optimal Mismatch
_MS, 			//Maximal shift
_QS, 			//Quick-Search
_TunBM, 		//Tuned Boyer-Moore
_NSN, 			//not so naive
_TBM,			//Turbo Boyer-Moore
_Col, 			//Colussi
_Smith, 		//Smith
_GG, 			//Galil-Giancarlo
_Raita, 		//Raita
_SMOA, 			//String Mtahcing on Ordered Alphabets
_RCol, 			//Reverse Colussi
_Skip, 			//Skip Serach
_KMPSkip, 		//KMP skip search
_ASkip, 		//Alpha-Skip-Search
_BR, 			//Berry-ravindran
_AKC,          //AKC algorithm
_FS,           //Fast-Search                                      
_FFS,          //Forward-Fast-Search                              
_BFS,          //Backward-Fast-Search, Fast-Boyer-Moore           
_TS,           //Tailed-Substring                                 
_SSABS,        //Sheik-Sumit-Anindya-Balakrishnan-Sekar           
_TVSBS,        //Thathoo-Virmani-Sai-Balakrishnan-Sekar           
_PBMH,         //Boyer-Moore-Horspool using Probabilities         
_FJS,          //Franek-Jennings-Smyth                            
_BLOCK,        //2-Block Boyer-Moore                              
_HASH3,        //Wu-Manber for Single Pattern Matching (q=3)            
_HASH5,        //Wu-Manber for Single Pattern Matching (q=5)
_HASH8,        //Wu-Manber for Single Pattern Matching (q=8)            
_TSW,          //Two-Sliding-Window                               
_BMH2,         //Boyer-Moore-Horspool with q-grams  (BMH2)
_BMH4,         //Boyer-Moore-Horspool with q-grams  (BMH4)              
_GRASPm,       //Genomic Rapid Algorithm for String Pattern-match 
_SSEF,         //SSEF (K=7)  
//Algorithms based on automata
_AUT, 			//Automaton Matcher
_RF, 			//Revrese-Factor
_TRF, 			//Turbo Reverse factor
_Simon, 		//Simon 
_FDM, 			//Forward-DAWG-Match
_BOM, 			//BOM
_BOM2, 			//BOM2
_DFDM,         //Double Forward DAWG Matching                     
_WW,           //Wide Window                                      
_LDM,		   //Linear DAWG Matching                
_ILDM1,        //ILDM1
_ILDM2,        //ILDM2
_EBOM,         //Extended Backward Oracle Matching                
_FBOM,         //Forward Backward Oracle Matching                 
_SEBOM,        //Simplified Extended Backward Oracle Matching                
_SFBOM,        //Simplified Forward Backward Oracle Matching 
_SBDM,         //Succint Backward DAWG Matching                   
//Algorithms based on bit-parallelism
_SO, 			//Shift-Or
_SA, 			//Shift-And
_BNDM,         //BNDM for Long patterns                           
_BNDML,        //BNDM for Long patterns                           
_SBNDM,        //Simplified BNDM                                  
_TNDM,         //Two-Way Nondeterministic DAWG Matching           
_TNDMa,        //Two-Way Nondeterministic DAWG Matching (version 2)
_LBNDM,        //Long patterns BNDM                               
_SVM0,         //Shift Vector Matching (version 0)                                                       
_SVM1,         //Shift Vector Matching (version 1)                           
_SVM2,         //Shift Vector Matching (version 2)                                                       
_SVM3,         //Shift Vector Matching (version 3)                                                       
_SVM4,         //Shift Vector Matching (version 4)                                                       
_SBNDM2,       //Simplified BNDM with loop-unrolling              
_SBNDMBMH,     //SBNDM with Horspool Shift                         
_BMHSBNDM,     //Horspool with SBNDM test                          
_FNDM,         //Forward Nondeterministic DAWG Matching           
_BWW,          //Bit parallel Wide Window                         
_FAOSOq2,      //Fast Average Optimal Shift-Or (u=2)                   
_FAOSOq4,      //Fast Average Optimal Shift-Or (u=2)                   
_FAOSOq6,      //Fast Average Optimal Shift-Or (u=2)                   
_AOSO2,        //Average Optimal Shift-Or (q=2)                        
_AOSO4,        //Average Optimal Shift-Or (q=4)                        
_AOSO6,        //Average Optimal Shift-Or (q=6)                        
_BLIM,         //Bit-Parallel Length Invariant Matcher            
_FSBNDM,       //Forward SBNDM                                    
_BNDMq2,       //BNDM with q-grams                                
_BNDMq4,       //BNDM with q-grams                                
_BNDMq6,       //BNDM with q-grams                                
_SBNDMq2,      //Simplified BNDM with q-grams                     
_SBNDMq4,      //Simplified BNDM with q-grams                     
_SBNDMq6,      //Simplified BNDM with q-grams                     
_SBNDMq8,      //Simplified BNDM with q-grams                     
_UFNDMq2,      //Shift-Or with q-grams                            
_UFNDMq4,      //Shift-Or with q-grams                            
_UFNDMq6,      //Shift-Or with q-grams                            
_UFNDMq8,      //Shift-Or with q-grams                            
_SABP,		   //Small Alphabet Bit Parallel                                            
_DBWW,		   //DOUBLE BWW
_DBWW2,		   //DOUBLE BWW
_KSA,		   //Factorized SHIFT-AND                                            
_KBNDM,		   //Factorized BNDM

} ALGO_POS;

/*
int execute(int algo, unsigned char *P, int m, unsigned char *T, int n, int *FREQ, int alpha) {
	switch(algo)  {
	/*************************************/
	/* PREVIOUS			     */
	/************************************
	case _MP:	 	 return MP(P,m,T,n);		break; 			//Morris-Pratt
	case _BM:	 	 return BM(P,m,T,n);		break; 			//Boyer-Moore
	case _KMP:	 	 return KMP(P,m,T,n);		break; 			//Knuth-Morris Pratt
	case _AG:	 	 return AG(P,m,T,n);		break; 			//Apostolico-Giancarlo
	case _ASkip:	 return ASKIP(P,m,T,n);		break; 			//Alpha-Skip-Search
	case _AUT:	 	 return AUT(P,m,T,n);		break; 			//Automaton Matcher
	case _AC:	 	 return AXAMAC(P,m,T,n);	break; 			//Apostolico-Crochemore
	case _BF:	 	 return BF(P,m,T,n);		break; 			//Brute Force
	case _BOM2:	 	 return BOM2(P,m,T,n);		break; 			//BOM2
	case _BOM:	 	 return BOM(P,m,T,n);		break; 			//BOM
	case _BR:	 	 return BR(P,m,T,n);		break; 			//Berry-ravindran
	case _Col:	 	 return COLUSSI(P,m,T,n);	break; 			//Colussi
	case _RF:	 	 return RF(P,m,T,n);		break; 			//Revrese-Factor
	case _FDM:	 	 return FDM(P,m,T,n);		break; 			//Forward-DAWG-Match
	case _GG:	 	 return GG(P,m,T,n);		break; 			//Galil-Giancarlo
	case _GS:	 	 return GS(P,m,T,n);		break; 			//Galil Seiferas
	case _HOR:	 	 return HORSPOOL(P,m,T,n);	break; 			//Hoorspool
	case _QS:	 	 return QS(P,m,T,n);		break; 			//Quick-Search
	case _KMPSkip:	 return KMPSKIP(P,m,T,n);	break; 			//KMP skip search
	case _KR:	 	 return KR(P,m,T,n);		break; 			//Karp-Rabin

	case _OM:	 	 return OM(P,m,T,n);		break; 			//Optimal Mismatch
	case _MS:	 	 return MS(P,m,T,n);		break; 			//Maximal shift
	case _NSN:	 	 return NSN(P,m,T,n);		break; 			//not so naive
	case _Raita:	 return RAITA(P,m,T,n);		break; 			//Raita
	case _RCol:	 	 return FS(P,m,T,n);		break; 			//Reverse Colussi
	case _Simon:	 return SIMON(P,m,T,n);		break; 			//Simon 
	case _Skip:	 	 return SKIP(P,m,T,n);		break; 			//Skip Serach
	case _Smith:	 return SMITH(P,m,T,n);		break; 			//Smith
	case _SMOA:	 	 return SMOA(P,m,T,n);		break; 			//String Mtahcing on Ordered Alphabets
	case _SO:	 	 return SO(P,m,T,n);		break; 			//Shift-Or
	case _SA:	 	 return SA(P,m,T,n);		break; 			//Shift-And
	case _TBM:	 	 return TBM(P,m,T,n);		break;			//Turbo Boyer-Moore
	case _TRF:	 	 return TRF(P,m,T,n);		break; 			//Turbo Reverse factor
	case _TunBM:	 return TUNEDBM(P,m,T,n);	break; 			//Tuned Boyer-Moore
	case _TW:	 	 return TW(P,m,T,n);		break; 			// Two-Way
	case _ZT:	 	 return ZT(P,m,T,n);		break; 			//Zhu-Takaoka
	/*************************************/
	/* COMPARISON			     */
	/************************************
	case _FS:	 	 return FS(P,m,T,n);		break;      //Fast-Search                                      
	case _FFS:       return FFS(P,m,T,n);		break;   	//Forward-Fast-Search                              
	case _BFS:		 return BFS(P,m,T,n);		break;   	//Backward-Fast-Search, Fast-Boyer-Moore           
	case _TS:        return TS(P,m,T,n);		break;   	//Tailed-Substring                                 
	case _SSABS:     return SSABS(P,m,T,n);		break;   	//Sheik-Sumit-Anindya-Balakrishnan-Sekar           
	case _TVSBS:     return TVSBS(P,m,T,n);		break;   	//Thathoo-Virmani-Sai-Balakrishnan-Sekar           
	case _PBMH:      return PBMH(P,m,T,n,FREQ);	break;   	//Boyer-Moore-Horspool using Probabilities         
	case _FJS:       return FJS(P,m,T,n);		break;   	//Franek-Jennings-Smyth                            
	//case _BLOCK:     return BLOCK(P,m,T,n);	break;  	//2-Block Boyer-Moore                              
	case _HASH3:     if(m>3) return HASH3(P,m,T,n);break; 	//Wu-Manber for Single Pattern Matching  (q=3)          
	case _HASH5:     if(m>5) return HASH5(P,m,T,n);break; 	//Wu-Manber for Single Pattern Matching  (q=5)          
	case _HASH8:     if(m>8) return HASH8(P,m,T,n);break; 	//Wu-Manber for Single Pattern Matching  (q=8)          
	case _TSW:       return TSW(P,m,T,n);		break;   	//Two-Sliding-Window                               
	//case _BMH2:      if(alpha<=4) return BMH2(P,m,T,n);break;   	//Boyer-Moore-Horspool with q-grams                
	//case _BMH4:      if(alpha<=16) return BMH4(P,m,T,n);break;   	//Boyer-Moore-Horspool with q-grams                
	case _GRASPm:    return GRASPm(P,m,T,n);	break;   	//Genomic Rapid Algorithm for String Pattern-match 
	case _AKC:    	 return AKC(P,m,T,n);		break;   	//AKC algorithm
	
	/*************************************/
	/* AUTOMATON			     */
	/************************************
	case _DFDM:      return DFDM(P,m,T,n,alpha);	break;          //Double Forward DAWG Matching                     
	case _WW:        return WW(P,m,T,n);		break;          //Wide Window                                      
	case _SBDM:      return HORSPOOL(P,m,T,n);	break;          //Succint Backward DAWG Matching
	case _EBOM:      return EBOM(P,m,T,n);		break;          //Extended Backward Oracle Matching                
	case _FBOM:      return FBOM(P,m,T,n);		break;          //Forward Backward Oracle Matching                 
	case _SEBOM:     return SEBOM(P,m,T,n);		break;          //Simplified Extended Backward Oracle Matching                
	case _SFBOM:     return SFBOM(P,m,T,n);		break;          //Simplified Forward Backward Oracle Matching                 
	case _LDM:       return LDM(P,m,T,n);		break;          //Linear DAWG Matching
	case _ILDM1:     return ILDM1(P,m,T,n);		break;          //ILDM1
	case _ILDM2:     return ILDM2(P,m,T,n);		break;          //ILDM2
	
	/*************************************/
	/* BIT PARALLELISM		     */
	/************************************
	case _BNDM:      return BNDM(P,m,T,n);		break;          //Simplified BNDM                                  
	case _BNDML:     return BNDML(P,m,T,n);		break;          //BNDM for Long patterns     
	case _SBNDM:     return SBNDM(P,m,T,n);		break;          //Simplified BNDM                                  
	case _TNDM:      return TNDM(P,m,T,n);		break;          //Two-Way Nondeterministic DAWG Matching           
	case _TNDMa:     return TNDMa(P,m,T,n);		break;          //Two-Way Nondeterministic DAWG Matching           
	case _LBNDM:     return LBNDM(P,m,T,n);		break;          //Long patterns BNDM                   
	case _SVM0:      return SVM0(P,m,T,n);		break;          //Shift Vector Matching (version 0)                
	case _SVM1:      return SVM1(P,m,T,n);		break;          //Shift Vector Matching (version 1)                
	case _SVM2:      return SVM2(P,m,T,n);		break;          //Shift Vector Matching (version 2)                
	case _SVM3:      return SVM3(P,m,T,n);		break;          //Shift Vector Matching (version 3)                
	case _SVM4:      return SVM4(P,m,T,n);		break;          //Shift Vector Matching (version 4)                
	case _SBNDM2:    return SBNDM2(P,m,T,n);	break;          //Simplified BNDM with loop-unrolling              
	case _SBNDMBMH:  return SBNDMBMH(P,m,T,n);	break;          //BNDM with Horspool Shift                         
	case _BMHSBNDM:  return BMHSBNDM(P,m,T,n);	break;          //Horspool with BNDM test                          
	case _FNDM:      return FNDM(P,m,T,n);		break;          //Forward Nondeterministic DAWG Matching           
	case _BWW:       return BWW(P,m,T,n);		break;          //Bit parallel Wide Window                         
	case _FAOSOq2:   return FAOSO(P,m,T,n,2);	break;          //Fast Average Optimal Shift-Or                    
	case _FAOSOq4:   return FAOSO(P,m,T,n,4);	break;          //Fast Average Optimal Shift-Or                    
	case _FAOSOq6:   return FAOSO(P,m,T,n,6);	break;          //Fast Average Optimal Shift-Or                    
	case _AOSO2:     return AOSO(P,m,T,n,2);	break;          //Average Optimal Shift-Or                         
	case _AOSO4:     return AOSO(P,m,T,n,4);	break;          //Average Optimal Shift-Or                         
	case _AOSO6:     return AOSO(P,m,T,n,6);	break;          //Average Optimal Shift-Or                         
	case _BLIM:      return BLIM(P,m,T,n);		break;          //Bit-Parallel Length Invariant Matcher            
	case _FSBNDM:    return FSBNDM(P,m,T,n);	break;          //Forward SBNDM                                    
	case _BNDMq2:    return BNDMQ2(P,m,T,n);	break;          //BNDM with q-grams                                
	case _BNDMq4:    return BNDMQ4(P,m,T,n);	break;          //BNDM with q-grams                                
	case _BNDMq6:    return BNDMQ6(P,m,T,n);	break;          //BNDM with q-grams                                
	case _SBNDMq2:   return SBNDMQ2(P,m,T,n);	break;          //Simplified BNDM with q-grams                     
	case _SBNDMq4:   return SBNDMQ4(P,m,T,n);	break;          //Simplified BNDM with q-grams                     
	case _SBNDMq6:   return SBNDMQ6(P,m,T,n);	break;          //Simplified BNDM with q-grams                     
	case _SBNDMq8:   return SBNDMQ8(P,m,T,n);	break;          //Simplified BNDM with q-grams                     
	case _UFNDMq2:   return UFNDMQ2(P,m,T,n);	break;          //Shift-Or with q-grams                            
	case _UFNDMq4:   return UFNDMQ4(P,m,T,n);	break;          //Shift-Or with q-grams                            
	case _UFNDMq6:   return UFNDMQ6(P,m,T,n);	break;          //Shift-Or with q-grams                            
	case _UFNDMq8:   return UFNDMQ8(P,m,T,n);	break;          //Shift-Or with q-grams                            
	case _SSEF:      return SSEF(P,m,T,n,7);	break;          //SSEF  (K=7)                                            
	case _SABP:      return SABP(P,m,T,n);		break;          //Small Alphabet Bit Parallel 
	case _KSA:	 	 return KSA(P,m,T,n);		break;          //Factorized SHIFT-AND
	case _KBNDM: 	 return KBNDM(P,m,T,n);		break;          //Factorized BNDM
	case _DBWW:	 	 return DBWW(P,m,T,n);		break;          //DOUBLE BWW
	case _DBWW2:	 return DBWW2(P,m,T,n);		break;          //DOUBLE BWW

	/*************************************/
	/* NEW ALGORITHMS		     */
	/************************************
	case _NEWHASH3:	return NEWHASH3(P,m,T,n);		break;          
	case _TVSBS_P2:	return TVSBS_P2(P,m,T,n);		break;          
	case _TVSBS_P4:	return TVSBS_P4(P,m,T,n);		break;          
	case _TVSBS_P6:	return TVSBS_P6(P,m,T,n);		break;          
	case _TVSBS_P8:	return TVSBS_P8(P,m,T,n);		break;          
	case _SBNDM_P2:	return SBNDM_P2(P,m,T,n);		break;          
	case _SBNDM_P4:	return SBNDM_P4(P,m,T,n);		break;          
	case _HORQS:	return HORQS(P,m,T,n);		break;          
	case _HORQS_P2:	return HORQS_P2(P,m,T,n);		break;          
	case _HORQS_P4:	return HORQS_P4(P,m,T,n);		break;          
	case _FS_P2:	return FS_P2(P,m,T,n);		break;          
	case _FS_P4:	return FS_P4(P,m,T,n);		break;          
	case _FS_P8:	return FS_P8(P,m,T,n);		break;          
	}
	return 0;
}*/
