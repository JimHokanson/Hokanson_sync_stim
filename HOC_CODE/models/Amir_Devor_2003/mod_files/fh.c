/* Created by Language version: 6.2.0 */
/* NOT VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib.h"
#undef PI
 
#include "md1redef.h"
#include "section.h"
#include "md2redef.h"

#if METHOD3
extern int _method3;
#endif

#undef exp
#define exp hoc_Exp
extern double hoc_Exp();
 
#define _threadargscomma_ /**/
#define _threadargs_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define pnabar _p[0]
#define ppbar _p[1]
#define pkbar _p[2]
#define gl _p[3]
#define el _p[4]
#define ip _p[5]
#define il _p[6]
#define m _p[7]
#define h _p[8]
#define n _p[9]
#define p _p[10]
#define nai _p[11]
#define nao _p[12]
#define ki _p[13]
#define ko _p[14]
#define Dm _p[15]
#define Dh _p[16]
#define Dn _p[17]
#define Dp _p[18]
#define ina _p[19]
#define ik _p[20]
#define _g _p[21]
#define _ion_nai	*_ppvar[0]._pval
#define _ion_nao	*_ppvar[1]._pval
#define _ion_ina	*_ppvar[2]._pval
#define _ion_dinadv	*_ppvar[3]._pval
#define _ion_ki	*_ppvar[4]._pval
#define _ion_ko	*_ppvar[5]._pval
#define _ion_ik	*_ppvar[6]._pval
#define _ion_dikdv	*_ppvar[7]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static int _hoc_alp();
 static int _hoc_bet();
 static int _hoc_expM1();
 static int _hoc_efun();
 static int _hoc_ghk();
 static int _hoc_mhnp();
 static int _mechtype;
extern int nrn_get_mechtype();
 static _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range();
 _prop = hoc_getdata_range(_mechtype);
 _p = _prop->param; _ppvar = _prop->dparam;
 ret(1.);
}
 /* connect user functions to hoc names */
 static IntFunc hoc_intfunc[] = {
 "setdata_fh", _hoc_setdata,
 "alp_fh", _hoc_alp,
 "bet_fh", _hoc_bet,
 "expM1_fh", _hoc_expM1,
 "efun_fh", _hoc_efun,
 "ghk_fh", _hoc_ghk,
 "mhnp_fh", _hoc_mhnp,
 0, 0
};
#define alp alp_fh
#define bet bet_fh
#define expM1 expM1_fh
#define efun efun_fh
#define ghk ghk_fh
 extern double alp();
 extern double bet();
 extern double expM1();
 extern double efun();
 extern double ghk();
 /* declare global and static user variables */
#define inf inf_fh
 double inf[4];
#define tau tau_fh
 double tau[4];
#define usetable usetable_fh
 double usetable = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_fh", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "tau_fh", "ms",
 "pnabar_fh", "cm/s",
 "ppbar_fh", "cm/s",
 "pkbar_fh", "cm/s",
 "gl_fh", "mho/cm2",
 "el_fh", "mV",
 "ip_fh", "mA/cm2",
 "il_fh", "mA/cm2",
 0,0
};
 static double delta_t = 1;
 static double h0 = 0;
 static double m0 = 0;
 static double n0 = 0;
 static double p0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "usetable_fh", &usetable_fh,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 "inf_fh", inf_fh, 4,
 "tau_fh", tau_fh, 4,
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(), nrn_init(), nrn_state();
 static void nrn_cur(), nrn_jacob();
 
static int _ode_count(), _ode_map(), _ode_spec(), _ode_matsol();
 
#define _cvode_ieq _ppvar[8]._i
 /* connect range variables in _p that hoc is supposed to know about */
 static char *_mechanism[] = {
 "6.2.0",
"fh",
 "pnabar_fh",
 "ppbar_fh",
 "pkbar_fh",
 "gl_fh",
 "el_fh",
 0,
 "ip_fh",
 "il_fh",
 0,
 "m_fh",
 "h_fh",
 "n_fh",
 "p_fh",
 0,
 0};
 static Symbol* _na_sym;
 static Symbol* _k_sym;
 
static void nrn_alloc(_prop)
	Prop *_prop;
{
	Prop *prop_ion, *need_memb();
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 22, _prop);
 	/*initialize range parameters*/
 	pnabar = 0.008;
 	ppbar = 0.00054;
 	pkbar = 0.0012;
 	gl = 0.0303;
 	el = -69.74;
 	_prop->param = _p;
 	_prop->param_size = 22;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 9, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* nai */
 	_ppvar[1]._pval = &prop_ion->param[2]; /* nao */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[4]._pval = &prop_ion->param[1]; /* ki */
 	_ppvar[5]._pval = &prop_ion->param[2]; /* ko */
 	_ppvar[6]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[7]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 _fh_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	ion_reg("k", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_dparam_size(_mechtype, 9);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 fh /cygdrive/C/D/SVN_FOLDERS/matlab_toolboxes/NEURON/HOC_CODE/models/Amir_Devor_2003/mod_files/fh.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 96485.3;
 static double R = 8.31342;
 static double *_t_inf[4];
 static double *_t_tau[4];
static int _reset;
static char *modelname = "FH channel";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static _modl_cleanup(){ _match_recurse=1;}
static _f_mhnp();
static mhnp();
 
static int _ode_spec1(), _ode_matsol1();
 static _n_mhnp();
 static int _slist1[4], _dlist1[4];
 static int states();
 
double ghk (  _lv , _lci , _lco )  
	double _lv , _lci , _lco ;
 {
   double _lghk;
 double _lz , _leci , _leco ;
 _lz = ( 1e-3 ) * FARADAY * _lv / ( R * ( celsius + 273.15 ) ) ;
   _leco = _lco * efun ( _threadargscomma_ _lz ) ;
   _leci = _lci * efun ( _threadargscomma_ - _lz ) ;
   _lghk = ( .001 ) * FARADAY * ( _leci - _leco ) ;
   
return _lghk;
 }
 
static int _hoc_ghk() {
  double _r;
   _r =  ghk (  *getarg(1) , *getarg(2) , *getarg(3) ) ;
 ret(_r);
}
 
double efun (  _lz )  
	double _lz ;
 {
   double _lefun;
 if ( fabs ( _lz ) < 1e-4 ) {
     _lefun = 1.0 - _lz / 2.0 ;
     }
   else {
     _lefun = _lz / ( exp ( _lz ) - 1.0 ) ;
     }
   
return _lefun;
 }
 
static int _hoc_efun() {
  double _r;
   _r =  efun (  *getarg(1) ) ;
 ret(_r);
}
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   mhnp ( _threadargscomma_ v * 1.0 ) ;
   Dm = ( inf [ 0 ] - m ) / tau [ 0 ] ;
   Dh = ( inf [ 1 ] - h ) / tau [ 1 ] ;
   Dn = ( inf [ 2 ] - n ) / tau [ 2 ] ;
   Dp = ( inf [ 3 ] - p ) / tau [ 3 ] ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 mhnp ( _threadargscomma_ v * 1.0 ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau[0] )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau[1] )) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau[2] )) ;
 Dp = Dp  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau[3] )) ;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   mhnp ( _threadargscomma_ v * 1.0 ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau[0])))*(- ( ( ( inf[0] ) ) / tau[0] ) / ( ( ( ( - 1.0) ) ) / tau[0] ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau[1])))*(- ( ( ( inf[1] ) ) / tau[1] ) / ( ( ( ( - 1.0) ) ) / tau[1] ) - h) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau[2])))*(- ( ( ( inf[2] ) ) / tau[2] ) / ( ( ( ( - 1.0) ) ) / tau[2] ) - n) ;
    p = p + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tau[3])))*(- ( ( ( inf[3] ) ) / tau[3] ) / ( ( ( ( - 1.0) ) ) / tau[3] ) - p) ;
   }
  return 0;
}
 
double alp (  _lv , _li )  
	double _lv , _li ;
 {
   double _lalp;
 double _la , _lb , _lc , _lq10 ;
 _lv = _lv + 70.0 ;
   _lq10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   if ( _li  == 0.0 ) {
     _la = .36 ;
     _lb = 22. ;
     _lc = 3. ;
     _lalp = _lq10 * _la * expM1 ( _threadargscomma_ _lb - _lv , _lc ) ;
     }
   else if ( _li  == 1.0 ) {
     _la = .1 ;
     _lb = - 10. ;
     _lc = 6. ;
     _lalp = _lq10 * _la * expM1 ( _threadargscomma_ _lv - _lb , _lc ) ;
     }
   else if ( _li  == 2.0 ) {
     _la = .02 ;
     _lb = 35. ;
     _lc = 10. ;
     _lalp = _lq10 * _la * expM1 ( _threadargscomma_ _lb - _lv , _lc ) ;
     }
   else {
     _la = .006 ;
     _lb = 40. ;
     _lc = 10. ;
     _lalp = _lq10 * _la * expM1 ( _threadargscomma_ _lb - _lv , _lc ) ;
     }
   
return _lalp;
 }
 
static int _hoc_alp() {
  double _r;
   _r =  alp (  *getarg(1) , *getarg(2) ) ;
 ret(_r);
}
 
double bet (  _lv , _li )  
	double _lv , _li ;
 {
   double _lbet;
 double _la , _lb , _lc , _lq10 ;
 _lv = _lv + 70.0 ;
   _lq10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   if ( _li  == 0.0 ) {
     _la = .4 ;
     _lb = 13. ;
     _lc = 20. ;
     _lbet = _lq10 * _la * expM1 ( _threadargscomma_ _lv - _lb , _lc ) ;
     }
   else if ( _li  == 1.0 ) {
     _la = 4.5 ;
     _lb = 45. ;
     _lc = 10. ;
     _lbet = _lq10 * _la / ( exp ( ( _lb - _lv ) / _lc ) + 1.0 ) ;
     }
   else if ( _li  == 2.0 ) {
     _la = .05 ;
     _lb = 10. ;
     _lc = 10. ;
     _lbet = _lq10 * _la * expM1 ( _threadargscomma_ _lv - _lb , _lc ) ;
     }
   else {
     _la = .09 ;
     _lb = - 25. ;
     _lc = 20. ;
     _lbet = _lq10 * _la * expM1 ( _threadargscomma_ _lv - _lb , _lc ) ;
     }
   
return _lbet;
 }
 
static int _hoc_bet() {
  double _r;
   _r =  bet (  *getarg(1) , *getarg(2) ) ;
 ret(_r);
}
 
double expM1 (  _lx , _ly )  
	double _lx , _ly ;
 {
   double _lexpM1;
 if ( fabs ( _lx / _ly ) < 1e-6 ) {
     _lexpM1 = _ly * ( 1.0 - _lx / _ly / 2.0 ) ;
     }
   else {
     _lexpM1 = _lx / ( exp ( _lx / _ly ) - 1.0 ) ;
     }
   
return _lexpM1;
 }
 
static int _hoc_expM1() {
  double _r;
   _r =  expM1 (  *getarg(1) , *getarg(2) ) ;
 ret(_r);
}
 static double _mfac_mhnp, _tmin_mhnp;
 static _check_mhnp();
 static _check_mhnp() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_celsius;
  if (!usetable) {return;}
  if (_sav_celsius != celsius) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_mhnp =  - 100.0 ;
   _tmax =  100.0 ;
   _dx = (_tmax - _tmin_mhnp)/200.; _mfac_mhnp = 1./_dx;
   for (_i=0, _x=_tmin_mhnp; _i < 201; _x += _dx, _i++) {
    _f_mhnp(_x);
    for (_j = 0; _j < 4; _j++) { _t_inf[_j][_i] = inf[_j];
}    for (_j = 0; _j < 4; _j++) { _t_tau[_j][_i] = tau[_j];
}   }
   _sav_celsius = celsius;
  }
 }

 static mhnp(double _lv){ _check_mhnp();
 _n_mhnp(_lv);
 return;
 }

 static _n_mhnp(double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_mhnp(_lv); return; 
}
 _xi = _mfac_mhnp * (_lv - _tmin_mhnp);
 _i = (int) _xi;
 if (_xi <= 0.) {
 for (_j = 0; _j < 4; _j++) { inf[_j] = _t_inf[_j][0];
} for (_j = 0; _j < 4; _j++) { tau[_j] = _t_tau[_j][0];
} return; }
 if (_i >= 200) {
 for (_j = 0; _j < 4; _j++) { inf[_j] = _t_inf[_j][200];
} for (_j = 0; _j < 4; _j++) { tau[_j] = _t_tau[_j][200];
} return; }
 _theta = _xi - (double)_i;
 for (_j = 0; _j < 4; _j++) {double *_t = _t_inf[_j]; inf[_j] = _t[_i] + _theta*(_t[_i+1] - _t[_i]);}
 for (_j = 0; _j < 4; _j++) {double *_t = _t_tau[_j]; tau[_j] = _t[_i] + _theta*(_t[_i+1] - _t[_i]);}
 }

 
static int  _f_mhnp (  _lv )  
	double _lv ;
 {
   double _la , _lb ;
 {int  _li ;for ( _li = 0 ; _li <= 3 ; _li ++ ) {
     _la = alp ( _threadargscomma_ _lv , ((double) _li ) ) ;
     _lb = bet ( _threadargscomma_ _lv , ((double) _li ) ) ;
     tau [ _li ] = 1.0 / ( _la + _lb ) ;
     inf [ _li ] = _la / ( _la + _lb ) ;
     } }
    return 0; }
 
static int _hoc_mhnp() {
  double _r;
    _r = 1.;
 mhnp (  *getarg(1) ) ;
 ret(_r);
}
 
static int _ode_count(_type) int _type;{ return 4;}
 
static int _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  nai = _ion_nai;
  nao = _ion_nao;
  ki = _ion_ki;
  ko = _ion_ko;
     _ode_spec1 ();
   }}
 
static int _ode_map(_ieq, _pv, _pvdot, _pp, _ppd, _atol, _type) int _ieq, _type; double** _pv, **_pvdot, *_pp, *_atol; Datum* _ppd; { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static int _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  nai = _ion_nai;
  nao = _ion_nao;
  ki = _ion_ki;
  ko = _ion_ko;
 _ode_matsol1 ();
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 2);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 3, 4);
   nrn_update_ion_pointer(_k_sym, _ppvar, 4, 1);
   nrn_update_ion_pointer(_k_sym, _ppvar, 5, 2);
   nrn_update_ion_pointer(_k_sym, _ppvar, 6, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 7, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  h = h0;
  m = m0;
  n = n0;
  p = p0;
 {
   mhnp ( _threadargscomma_ v * 1.0 ) ;
   m = inf [ 0 ] ;
   h = inf [ 1 ] ;
   n = inf [ 2 ] ;
   p = inf [ 3 ] ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  nai = _ion_nai;
  nao = _ion_nao;
  ki = _ion_ki;
  ko = _ion_ko;
 initmodel();
  }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   double _lghkna ;
 _lghkna = ghk ( _threadargscomma_ v , nai , nao ) ;
   ina = pnabar * m * m * h * _lghkna ;
   ip = ppbar * p * p * _lghkna ;
   ik = pkbar * n * n * ghk ( _threadargscomma_ v , ki , ko ) ;
   il = gl * ( v - el ) ;
   }
 _current += ina;
 _current += ik;
 _current += il;
 _current += ip;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  nai = _ion_nai;
  nao = _ion_nao;
  ki = _ion_ki;
  ko = _ion_ko;
 _g = _nrn_current(_v + .001);
 	{ double _dik;
 double _dina;
  _dina = ina;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 ;
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
 double _break, _save;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
  nai = _ion_nai;
  nao = _ion_nao;
  ki = _ion_ki;
  ko = _ion_ko;
 { {
 for (; t < _break; t += dt) {
 error =  states();
 if(error){fprintf(stderr,"at line 49 in file fh.mod:\n	SOLVE states METHOD cnexp\n"); nrn_complain(_p); abort_run(error);}
 
}}
 t = _save;
 }  }}

}

static terminal(){}

static _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
 _slist1[1] = &(h) - _p;  _dlist1[1] = &(Dh) - _p;
 _slist1[2] = &(n) - _p;  _dlist1[2] = &(Dn) - _p;
 _slist1[3] = &(p) - _p;  _dlist1[3] = &(Dp) - _p;
  for (_i=0; _i < 4; _i++) {  _t_inf[_i] = makevector(201*sizeof(double)); }
  for (_i=0; _i < 4; _i++) {  _t_tau[_i] = makevector(201*sizeof(double)); }
_first = 0;
}
