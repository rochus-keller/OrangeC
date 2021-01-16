#include <unordered_map>

#include "InstructionParser.h"

enum e_opcode
{
    op_aaa = 32,
    op_aad = 33,
    op_aam = 34,
    op_aas = 35,
    op_adc = 36,
    op_add = 37,
    op_and = 38,
    op_arpl = 39,
    op_bound = 40,
    op_bsf = 41,
    op_bsr = 42,
    op_bswap = 43,
    op_bt = 44,
    op_btc = 45,
    op_btr = 46,
    op_bts = 47,
    op_call = 48,
    op_cbw = 49,
    op_cdq = 50,
    op_cdqe = 51,
    op_clc = 52,
    op_cld = 53,
    op_cli = 54,
    op_clts = 55,
    op_cmc = 56,
    op_cmova = 57,
    op_cmovae = 58,
    op_cmovb = 59,
    op_cmovbe = 60,
    op_cmovc = 61,
    op_cmove = 62,
    op_cmovg = 63,
    op_cmovge = 64,
    op_cmovl = 65,
    op_cmovle = 66,
    op_cmovna = 67,
    op_cmovnae = 68,
    op_cmovnb = 69,
    op_cmovnbe = 70,
    op_cmovnc = 71,
    op_cmovne = 72,
    op_cmovng = 73,
    op_cmovnge = 74,
    op_cmovnl = 75,
    op_cmovnle = 76,
    op_cmovno = 77,
    op_cmovnp = 78,
    op_cmovns = 79,
    op_cmovnz = 80,
    op_cmovo = 81,
    op_cmovp = 82,
    op_cmovpe = 83,
    op_cmovpo = 84,
    op_cmovs = 85,
    op_cmovz = 86,
    op_cmp = 87,
    op_cmps = 88,
    op_cmpsb = 89,
    op_cmpsw = 90,
    op_cmpsd = 91,
    op_cmpsq = 92,
    op_cmpxchg = 93,
    op_cmpxchg8b = 94,
    op_cmpxchg16b = 95,
    op_cpuid = 96,
    op_cqo = 97,
    op_cwd = 98,
    op_cwde = 99,
    op_daa = 100,
    op_das = 101,
    op_dec = 102,
    op_div = 103,
    op_enter = 104,
    op_esc = 105,
    op_f2xm1 = 106,
    op_fabs = 107,
    op_fadd = 108,
    op_faddp = 109,
    op_fbld = 110,
    op_fbstp = 111,
    op_fchs = 112,
    op_fclex = 113,
    op_fnclex = 114,
    op_fcmovb = 115,
    op_fcmovbe = 116,
    op_fcmove = 117,
    op_fcmovnb = 118,
    op_fcmovnbe = 119,
    op_fcmovne = 120,
    op_fcmovnu = 121,
    op_fcmovu = 122,
    op_fcom = 123,
    op_fcomi = 124,
    op_fcomip = 125,
    op_fcomp = 126,
    op_fcompp = 127,
    op_fcos = 128,
    op_fdecstp = 129,
    op_fdisi = 130,
    op_fdiv = 131,
    op_fdivp = 132,
    op_fdivr = 133,
    op_fdivrp = 134,
    op_feni = 135,
    op_ffree = 136,
    op_ffreep = 137,
    op_fiadd = 138,
    op_ficom = 139,
    op_ficomp = 140,
    op_fidiv = 141,
    op_fidivr = 142,
    op_fild = 143,
    op_fimul = 144,
    op_fincstp = 145,
    op_finit = 146,
    op_fninit = 147,
    op_fist = 148,
    op_fistp = 149,
    op_fisub = 150,
    op_fisubr = 151,
    op_fld = 152,
    op_fld1 = 153,
    op_fldcw = 154,
    op_fldenv = 155,
    op_fldl2e = 156,
    op_fldl2t = 157,
    op_fldlg2 = 158,
    op_fldln2 = 159,
    op_fldpi = 160,
    op_fldz = 161,
    op_fmul = 162,
    op_fmulp = 163,
    op_fnop = 164,
    op_fnsave = 165,
    op_fpatan = 166,
    op_fprem = 167,
    op_fprem1 = 168,
    op_fptan = 169,
    op_frndint = 170,
    op_frstor = 171,
    op_fsave = 172,
    op_fscale = 173,
    op_fsetpm = 174,
    op_fsin = 175,
    op_fsincos = 176,
    op_fsqrt = 177,
    op_fst = 178,
    op_fstcw = 179,
    op_fnstcw = 180,
    op_fstenv = 181,
    op_fnstenv = 182,
    op_fstp = 183,
    op_fstsw = 184,
    op_fnstsw = 185,
    op_fsub = 186,
    op_fsubp = 187,
    op_fsubr = 188,
    op_fsubrp = 189,
    op_ftst = 190,
    op_fucom = 191,
    op_fucomi = 192,
    op_fucomip = 193,
    op_fucomp = 194,
    op_fucompp = 195,
    op_fwait = 196,
    op_fxam = 197,
    op_fxch = 198,
    op_fxch4 = 199,
    op_fxch7 = 200,
    op_fxrstor = 201,
    op_fxsave = 202,
    op_fxtract = 203,
    op_fyl2x = 204,
    op_fyl2xp1 = 205,
    op_hlt = 206,
    op_icebp = 207,
    op_idiv = 208,
    op_imul = 209,
    op_in = 210,
    op_ins = 211,
    op_insb = 212,
    op_insw = 213,
    op_insd = 214,
    op_inc = 215,
    op_int = 216,
    op_int1 = 217,
    op_int3 = 218,
    op_into = 219,
    op_invd = 220,
    op_invlpg = 221,
    op_iret = 222,
    op_iretw = 223,
    op_iretd = 224,
    op_iretq = 225,
    op_ja = 226,
    op_jae = 227,
    op_jb = 228,
    op_jbe = 229,
    op_jc = 230,
    op_jcxz = 231,
    op_jecxz = 232,
    op_je = 233,
    op_jg = 234,
    op_jge = 235,
    op_jl = 236,
    op_jle = 237,
    op_jmp = 238,
    op_jna = 239,
    op_jnae = 240,
    op_jnb = 241,
    op_jnbe = 242,
    op_jnc = 243,
    op_jne = 244,
    op_jng = 245,
    op_jnge = 246,
    op_jnl = 247,
    op_jnle = 248,
    op_jno = 249,
    op_jnp = 250,
    op_jns = 251,
    op_jnz = 252,
    op_jo = 253,
    op_jp = 254,
    op_jpe = 255,
    op_jpo = 256,
    op_js = 257,
    op_jz = 258,
    op_lahf = 259,
    op_lar = 260,
    op_lds = 261,
    op_lea = 262,
    op_leave = 263,
    op_les = 264,
    op_lfence = 265,
    op_lfs = 266,
    op_lgdt = 267,
    op_lgs = 268,
    op_lidt = 269,
    op_lldt = 270,
    op_lmsw = 271,
    op_lods = 272,
    op_lodsb = 273,
    op_lodsw = 274,
    op_lodsd = 275,
    op_lodsq = 276,
    op_loop = 277,
    op_loope = 278,
    op_loopne = 279,
    op_loopnz = 280,
    op_loopz = 281,
    op_lsl = 282,
    op_lss = 283,
    op_ltr = 284,
    op_mov = 285,
    op_movs = 286,
    op_movbe = 287,
    op_movsb = 288,
    op_movsw = 289,
    op_movsd = 290,
    op_movsq = 291,
    op_movsx = 292,
    op_movzx = 293,
    op_movsxd = 294,
    op_mul = 295,
    op_neg = 296,
    op_nop = 297,
    op_not = 298,
    op_or = 299,
    op_out = 300,
    op_outs = 301,
    op_outsb = 302,
    op_outsw = 303,
    op_outsd = 304,
    op_pop = 305,
    op_popa = 306,
    op_popaw = 307,
    op_popad = 308,
    op_popcnt = 309,
    op_popf = 310,
    op_popfw = 311,
    op_popfd = 312,
    op_popfq = 313,
    op_prefetchnta = 314,
    op_prefetcht0 = 315,
    op_prefetcht1 = 316,
    op_prefetcht2 = 317,
    op_push = 318,
    op_pusha = 319,
    op_pushaw = 320,
    op_pushad = 321,
    op_pushf = 322,
    op_pushfw = 323,
    op_pushfd = 324,
    op_pushfq = 325,
    op_rcl = 326,
    op_rcr = 327,
    op_rdmsr = 328,
    op_rdpmc = 329,
    op_rdtsc = 330,
    op_ret = 331,
    op_retf = 332,
    op_rol = 333,
    op_ror = 334,
    op_rsm = 335,
    op_sahf = 336,
    op_sal = 337,
    op_sar = 338,
    op_sbb = 339,
    op_scas = 340,
    op_scasb = 341,
    op_scasw = 342,
    op_scasd = 343,
    op_scasq = 344,
    op_seta = 345,
    op_setae = 346,
    op_setb = 347,
    op_setbe = 348,
    op_setc = 349,
    op_sete = 350,
    op_setg = 351,
    op_setge = 352,
    op_setl = 353,
    op_setle = 354,
    op_setna = 355,
    op_setnae = 356,
    op_setnb = 357,
    op_setnbe = 358,
    op_setnc = 359,
    op_setne = 360,
    op_setng = 361,
    op_setnge = 362,
    op_setnl = 363,
    op_setnle = 364,
    op_setno = 365,
    op_setnp = 366,
    op_setns = 367,
    op_setnz = 368,
    op_seto = 369,
    op_setp = 370,
    op_setpe = 371,
    op_setpo = 372,
    op_sets = 373,
    op_setz = 374,
    op_sfence = 375,
    op_sgdt = 376,
    op_shl = 377,
    op_shld = 378,
    op_shr = 379,
    op_shrd = 380,
    op_sidt = 381,
    op_sldt = 382,
    op_smsw = 383,
    op_stc = 384,
    op_std = 385,
    op_sti = 386,
    op_stos = 387,
    op_stosb = 388,
    op_stosw = 389,
    op_stosd = 390,
    op_stosq = 391,
    op_str = 392,
    op_sub = 393,
    op_syscall = 394,
    op_sysenter = 395,
    op_sysexit = 396,
    op_sysret = 397,
    op_test = 398,
    op_ud2 = 399,
    op_verr = 400,
    op_verw = 401,
    op_wait = 402,
    op_wbinvd = 403,
    op_wrmsr = 404,
    op_xadd = 405,
    op_xchg = 406,
    op_xlat = 407,
    op_xlatb = 408,
    op_xor = 409,
    op_xrstor = 410,
    op_xrstor64 = 411,
    op_xsave = 412,
    op_xsave64 = 413,
    op_xsetbv = 414,
    op_addpd = 415,
    op_addps = 416,
    op_addsd = 417,
    op_addss = 418,
    op_addsubpd = 419,
    op_addsubps = 420,
    op_andnpd = 421,
    op_andnps = 422,
    op_andpd = 423,
    op_andps = 424,
    op_blendpd = 425,
    op_blendps = 426,
    op_cmppd = 427,
    op_cmpps = 428,
    op_comisd = 429,
    op_comiss = 430,
    op_cvtdq2pd = 431,
    op_cvtdq2ps = 432,
    op_cvtpd2dq = 433,
    op_cvtpd2pi = 434,
    op_cvtpd2ps = 435,
    op_cvtpi2pd = 436,
    op_cvtpi2ps = 437,
    op_cvtps2dq = 438,
    op_cvtps2pd = 439,
    op_cvtps2pi = 440,
    op_cvtsd2si = 441,
    op_cvtsd2ss = 442,
    op_cvtsi2sd = 443,
    op_cvtsi2ss = 444,
    op_cvtss2sd = 445,
    op_cvtss2si = 446,
    op_cvttpd2dq = 447,
    op_cvttpd2pi = 448,
    op_cvttps2dq = 449,
    op_cvttps2pi = 450,
    op_cvttsd2si = 451,
    op_cvttss2si = 452,
    op_divpd = 453,
    op_divps = 454,
    op_divsd = 455,
    op_divss = 456,
    op_dppd = 457,
    op_dpps = 458,
    op_hsubpd = 459,
    op_hsubps = 460,
    op_insertps = 461,
    op_lddqu = 462,
    op_maskmovdqu = 463,
    op_maskmovq = 464,
    op_maxpd = 465,
    op_maxps = 466,
    op_maxsd = 467,
    op_maxss = 468,
    op_mfence = 469,
    op_minpd = 470,
    op_minps = 471,
    op_minsd = 472,
    op_minss = 473,
    op_monitor = 474,
    op_movapd = 475,
    op_movaps = 476,
    op_movd = 477,
    op_movq = 478,
    op_movddup = 479,
    op_movdq2q = 480,
    op_movdqa = 481,
    op_movdqu = 482,
    op_movhlps = 483,
    op_movhpd = 484,
    op_movhps = 485,
    op_movlhps = 486,
    op_movlpd = 487,
    op_movlps = 488,
    op_movmskpd = 489,
    op_movmskps = 490,
    op_movntdq = 491,
    op_movnti = 492,
    op_movntpd = 493,
    op_movntd = 494,
    op_movntq = 495,
    op_movq2dq = 496,
    op_movshdup = 497,
    op_movsldup = 498,
    op_movss = 499,
    op_movupd = 500,
    op_movups = 501,
    op_mpsadbw = 502,
    op_mulpd = 503,
    op_mulps = 504,
    op_mulsd = 505,
    op_mulss = 506,
    op_orpd = 507,
    op_orps = 508,
    op_packssdw = 509,
    op_packsswb = 510,
    op_packusdw = 511,
    op_paddb = 512,
    op_paddd = 513,
    op_paddq = 514,
    op_paddsw = 515,
    op_paddusb = 516,
    op_paddusw = 517,
    op_paddw = 518,
    op_palignr = 519,
    op_pand = 520,
    op_pandn = 521,
    op_pavgb = 522,
    op_pavgw = 523,
    op_pblendw = 524,
    op_pcmpeqb = 525,
    op_pcmpeqd = 526,
    op_pcmpeqw = 527,
    op_pcmpestri = 528,
    op_pcmpestrm = 529,
    op_pcmpgtb = 530,
    op_pcmpgtd = 531,
    op_pcmpgtw = 532,
    op_pextrb = 533,
    op_pextrd = 534,
    op_pextrq = 535,
    op_pextrw = 536,
    op_pinsrb = 537,
    op_pinsrd = 538,
    op_pinsrq = 539,
    op_pinsrw = 540,
    op_pmaddwd = 541,
    op_pmaxsw = 542,
    op_pmaxub = 543,
    op_pminsw = 544,
    op_pminub = 545,
    op_pmovmskb = 546,
    op_pmulhuw = 547,
    op_pmulhw = 548,
    op_pmullw = 549,
    op_pmuludq = 550,
    op_psadbw = 551,
    op_pshufd = 552,
    op_pshufhw = 553,
    op_pshuflw = 554,
    op_pshufw = 555,
    op_pslld = 556,
    op_pslldq = 557,
    op_psllq = 558,
    op_psllw = 559,
    op_psrad = 560,
    op_psraw = 561,
    op_psrld = 562,
    op_psrldq = 563,
    op_psrlq = 564,
    op_psrlw = 565,
    op_psubb = 566,
    op_psubd = 567,
    op_psubq = 568,
    op_psubsb = 569,
    op_psubsw = 570,
    op_psubusb = 571,
    op_psubusw = 572,
    op_punpckhbw = 573,
    op_punpckhdq = 574,
    op_punpckhqdq = 575,
    op_punpckhwd = 576,
    op_punpcklbw = 577,
    op_punpckldq = 578,
    op_punpcklqdq = 579,
    op_punpcklwd = 580,
    op_pxor = 581,
    op_rcpps = 582,
    op_rcpss = 583,
    op_roundpd = 584,
    op_roundps = 585,
    op_roundsd = 586,
    op_roundss = 587,
    op_rsqrtps = 588,
    op_rsqrtss = 589,
    op_shufpd = 590,
    op_shufps = 591,
    op_sqrtpd = 592,
    op_sqrtps = 593,
    op_sqrtsd = 594,
    op_sqrtss = 595,
    op_subpd = 596,
    op_subps = 597,
    op_subsd = 598,
    op_subss = 599,
    op_ucomisd = 600,
    op_ucomiss = 601,
    op_unpckhpd = 602,
    op_unpckhps = 603,
    op_unpcklpd = 604,
    op_unpcklps = 605,
    op_xorpd = 606,
    op_xorps = 607,
    op_invept = 608,
    op_invvpid = 609,
    op_vmcall = 610,
    op_vmclear = 611,
    op_vmlaunch = 612,
    op_vmptrld = 613,
    op_vmptrst = 614,
    op_vmread = 615,
    op_vmresume = 616,
    op_vmwrite = 617,
    op_vmxoff = 618,
    op_vmxon = 619,
    op_a16 = 620,
    op_a32 = 621,
    op_lock = 622,
    op_o16 = 623,
    op_o32 = 624,
    op_rep = 625,
    op_repe = 626,
    op_repne = 627,
    op_repnz = 628,
    op_repz = 629,
};

enum e_tk
{
    tk_star = 5,
    tk_plus = 4,
    tk_comma = 7,
    tk_colon = 3,
    tk_openbr = 1,
    tk_closebr = 2,
    tk_byte = 11,
    tk_dword = 9,
    tk_far = 15,
    tk_near = 14,
    tk_qword = 10,
    tk_short = 13,
    tk_tword = 12,
    tk_word = 8,
    tk_al = 1000,
    tk_ah = 1001,
    tk_ax = 1002,
    tk_eax = 1003,
    tk_rax = 1004,
    tk_r8b = 1005,
    tk_r8w = 1006,
    tk_r8d = 1007,
    tk_r8 = 1008,
    tk_cl = 1009,
    tk_ch = 1010,
    tk_cx = 1011,
    tk_ecx = 1012,
    tk_rcx = 1013,
    tk_r9b = 1014,
    tk_r9w = 1015,
    tk_r9d = 1016,
    tk_r9 = 1017,
    tk_dl = 1018,
    tk_dh = 1019,
    tk_dx = 1020,
    tk_edx = 1021,
    tk_rdx = 1022,
    tk_r10b = 1023,
    tk_r10w = 1024,
    tk_r10d = 1025,
    tk_r10 = 1026,
    tk_bl = 1027,
    tk_bh = 1028,
    tk_bx = 1029,
    tk_ebx = 1030,
    tk_rbx = 1031,
    tk_r11b = 1032,
    tk_r11w = 1033,
    tk_r11d = 1034,
    tk_r11 = 1035,
    tk_spl = 1036,
    tk_sp = 1037,
    tk_esp = 1038,
    tk_rsp = 1039,
    tk_r12b = 1040,
    tk_r12w = 1041,
    tk_r12d = 1042,
    tk_r12 = 1043,
    tk_bpl = 1044,
    tk_bp = 1045,
    tk_ebp = 1046,
    tk_rbp = 1047,
    tk_r13b = 1048,
    tk_r13w = 1049,
    tk_r13d = 1050,
    tk_r13 = 1051,
    tk_sil = 1052,
    tk_si = 1053,
    tk_esi = 1054,
    tk_rsi = 1055,
    tk_r14b = 1056,
    tk_r14w = 1057,
    tk_r14d = 1058,
    tk_r14 = 1059,
    tk_dil = 1060,
    tk_di = 1061,
    tk_edi = 1062,
    tk_rdi = 1063,
    tk_r15b = 1064,
    tk_r15w = 1065,
    tk_r15d = 1066,
    tk_r15 = 1067,
    tk_rip = 1068,
    tk_mm0 = 1069,
    tk_xmm0 = 1070,
    tk_xmm8 = 1071,
    tk_mm1 = 1072,
    tk_xmm1 = 1073,
    tk_xmm9 = 1074,
    tk_mm2 = 1075,
    tk_xmm2 = 1076,
    tk_xmm10 = 1077,
    tk_mm3 = 1078,
    tk_xmm3 = 1079,
    tk_xmm11 = 1080,
    tk_mm4 = 1081,
    tk_xmm4 = 1082,
    tk_xmm12 = 1083,
    tk_mm5 = 1084,
    tk_xmm5 = 1085,
    tk_xmm13 = 1086,
    tk_mm6 = 1087,
    tk_xmm6 = 1088,
    tk_xmm14 = 1089,
    tk_mm7 = 1090,
    tk_xmm7 = 1091,
    tk_xmm15 = 1092,
    tk_es = 1093,
    tk_cs = 1094,
    tk_ss = 1095,
    tk_ds = 1096,
    tk_fs = 1097,
    tk_gs = 1098,
    tk_st0 = 1099,
    tk_st1 = 1100,
    tk_st2 = 1101,
    tk_st3 = 1102,
    tk_st4 = 1103,
    tk_st5 = 1104,
    tk_st6 = 1105,
    tk_st7 = 1106,
    tk_cr0 = 1107,
    tk_cr1 = 1108,
    tk_cr2 = 1109,
    tk_cr3 = 1110,
    tk_cr4 = 1111,
    tk_cr5 = 1112,
    tk_cr6 = 1113,
    tk_cr7 = 1114,
    tk_dr0 = 1115,
    tk_dr1 = 1116,
    tk_dr2 = 1117,
    tk_dr3 = 1118,
    tk_dr4 = 1119,
    tk_dr5 = 1120,
    tk_dr6 = 1121,
    tk_dr7 = 1122,
    tk_tr0 = 1123,
    tk_tr1 = 1124,
    tk_tr2 = 1125,
    tk_tr3 = 1126,
    tk_tr4 = 1127,
    tk_tr5 = 1128,
    tk_tr6 = 1129,
    tk_tr7 = 1130,
};

extern const char* const opcodeTable[630];

extern std::unordered_map<enum e_tk, const char*> tokenNames;

extern InputToken Tokenstar;
extern InputToken Tokenplus;
extern InputToken Tokencomma;
extern InputToken Tokencolon;
extern InputToken Tokenopenbr;
extern InputToken Tokenclosebr;
extern InputToken Tokenbyte;
extern InputToken Tokendword;
extern InputToken Tokenempty;
extern InputToken Tokenfar;
extern InputToken Tokennear;
extern InputToken Tokenqword;
extern InputToken Tokenshort;
extern InputToken Tokentword;
extern InputToken Tokenword;
extern InputToken Tokenal;
extern InputToken Tokenah;
extern InputToken Tokenax;
extern InputToken Tokeneax;
extern InputToken Tokenrax;
extern InputToken Tokenr8b;
extern InputToken Tokenr8w;
extern InputToken Tokenr8d;
extern InputToken Tokenr8;
extern InputToken Tokencl;
extern InputToken Tokench;
extern InputToken Tokencx;
extern InputToken Tokenecx;
extern InputToken Tokenrcx;
extern InputToken Tokenr9b;
extern InputToken Tokenr9w;
extern InputToken Tokenr9d;
extern InputToken Tokenr9;
extern InputToken Tokendl;
extern InputToken Tokendh;
extern InputToken Tokendx;
extern InputToken Tokenedx;
extern InputToken Tokenrdx;
extern InputToken Tokenr10b;
extern InputToken Tokenr10w;
extern InputToken Tokenr10d;
extern InputToken Tokenr10;
extern InputToken Tokenbl;
extern InputToken Tokenbh;
extern InputToken Tokenbx;
extern InputToken Tokenebx;
extern InputToken Tokenrbx;
extern InputToken Tokenr11b;
extern InputToken Tokenr11w;
extern InputToken Tokenr11d;
extern InputToken Tokenr11;
extern InputToken Tokenspl;
extern InputToken Tokensp;
extern InputToken Tokenesp;
extern InputToken Tokenrsp;
extern InputToken Tokenr12b;
extern InputToken Tokenr12w;
extern InputToken Tokenr12d;
extern InputToken Tokenr12;
extern InputToken Tokenbpl;
extern InputToken Tokenbp;
extern InputToken Tokenebp;
extern InputToken Tokenrbp;
extern InputToken Tokenr13b;
extern InputToken Tokenr13w;
extern InputToken Tokenr13d;
extern InputToken Tokenr13;
extern InputToken Tokensil;
extern InputToken Tokensi;
extern InputToken Tokenesi;
extern InputToken Tokenrsi;
extern InputToken Tokenr14b;
extern InputToken Tokenr14w;
extern InputToken Tokenr14d;
extern InputToken Tokenr14;
extern InputToken Tokendil;
extern InputToken Tokendi;
extern InputToken Tokenedi;
extern InputToken Tokenrdi;
extern InputToken Tokenr15b;
extern InputToken Tokenr15w;
extern InputToken Tokenr15d;
extern InputToken Tokenr15;
extern InputToken Tokenrip;
extern InputToken Tokenmm0;
extern InputToken Tokenxmm0;
extern InputToken Tokenxmm8;
extern InputToken Tokenmm1;
extern InputToken Tokenxmm1;
extern InputToken Tokenxmm9;
extern InputToken Tokenmm2;
extern InputToken Tokenxmm2;
extern InputToken Tokenxmm10;
extern InputToken Tokenmm3;
extern InputToken Tokenxmm3;
extern InputToken Tokenxmm11;
extern InputToken Tokenmm4;
extern InputToken Tokenxmm4;
extern InputToken Tokenxmm12;
extern InputToken Tokenmm5;
extern InputToken Tokenxmm5;
extern InputToken Tokenxmm13;
extern InputToken Tokenmm6;
extern InputToken Tokenxmm6;
extern InputToken Tokenxmm14;
extern InputToken Tokenmm7;
extern InputToken Tokenxmm7;
extern InputToken Tokenxmm15;
extern InputToken Tokenes;
extern InputToken Tokencs;
extern InputToken Tokenss;
extern InputToken Tokends;
extern InputToken Tokenfs;
extern InputToken Tokengs;
extern InputToken Tokenst0;
extern InputToken Tokenst1;
extern InputToken Tokenst2;
extern InputToken Tokenst3;
extern InputToken Tokenst4;
extern InputToken Tokenst5;
extern InputToken Tokenst6;
extern InputToken Tokenst7;
extern InputToken Tokencr0;
extern InputToken Tokencr1;
extern InputToken Tokencr2;
extern InputToken Tokencr3;
extern InputToken Tokencr4;
extern InputToken Tokencr5;
extern InputToken Tokencr6;
extern InputToken Tokencr7;
extern InputToken Tokendr0;
extern InputToken Tokendr1;
extern InputToken Tokendr2;
extern InputToken Tokendr3;
extern InputToken Tokendr4;
extern InputToken Tokendr5;
extern InputToken Tokendr6;
extern InputToken Tokendr7;
extern InputToken Tokentr0;
extern InputToken Tokentr1;
extern InputToken Tokentr2;
extern InputToken Tokentr3;
extern InputToken Tokentr4;
extern InputToken Tokentr5;
extern InputToken Tokentr6;
extern InputToken Tokentr7;
