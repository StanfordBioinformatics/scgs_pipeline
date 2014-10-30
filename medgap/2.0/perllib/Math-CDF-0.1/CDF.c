/*
 * This file was generated automatically by xsubpp version 1.9508 from the
 * contents of CDF.xs. Do not edit this file, edit CDF.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "CDF.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "cdflib/cdflib.h"

#ifndef PATCHLEVEL
#include <patchlevel.h>
#endif

#if defined(PATCHLEVEL) && (PATCHLEVEL < 5)
#define PL_sv_undef    sv_undef
#endif

static int
not_here(char *s)
{
    croak("%s not implemented on this architecture", s);
    return -1;
}

static double
constant(char *name, int arg)
{
    errno = 0;
    switch (*name) {
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}


#line 46 "CDF.c"

XS(XS_Math__CDF_constant); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_constant)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Math::CDF::constant(name, arg)");
    {
	char *	name = (char *)SvPV_nolen(ST(0));
	int	arg = (int)SvIV(ST(1));
	double	RETVAL;
	dXSTARG;

	RETVAL = constant(name, arg);
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_pnorm); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_pnorm)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Math::CDF::pnorm(z)");
    {
	double	z = (double)SvNV(ST(0));
#line 51 "CDF.xs"
	int which=1, status;
	double p, q, mean=0.0, sd=1.0, bound;
#line 78 "CDF.c"
	SV *	RETVAL;
#line 54 "CDF.xs"
	ST(0) = sv_newmortal();
	(void)cdfnor(&which, &p, &q, &z, &mean, &sd, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)p );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 89 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_qnorm); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_qnorm)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Math::CDF::qnorm(p)");
    {
	double	p = (double)SvNV(ST(0));
#line 67 "CDF.xs"
	int which=2, status;
	double z, q, mean=0.0, sd=1.0, bound;
#line 106 "CDF.c"
	SV *	RETVAL;
#line 70 "CDF.xs"
	q = 1.0 - p;
	ST(0) = sv_newmortal();
	(void)cdfnor(&which, &p, &q, &z, &mean, &sd, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)z );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 118 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_pt); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_pt)
{
    dXSARGS;
    if (items < 2 || items > 3)
	Perl_croak(aTHX_ "Usage: Math::CDF::pt(t, df, ncp = 0.0)");
    {
	double	t = (double)SvNV(ST(0));
	double	df = (double)SvNV(ST(1));
	double	ncp;
#line 86 "CDF.xs"
	int which=1, status;
	double p, q, bound;
#line 137 "CDF.c"
	SV *	RETVAL;

	if (items < 3)
	    ncp = 0.0;
	else {
	    ncp = (double)SvNV(ST(2));
	}
#line 89 "CDF.xs"
	ST(0) = sv_newmortal();
	(void)cdftnc(&which, &p, &q, &t, &df, &ncp, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)p );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 154 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_qt); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_qt)
{
    dXSARGS;
    if (items < 2 || items > 3)
	Perl_croak(aTHX_ "Usage: Math::CDF::qt(p, df, ncp = 0.0)");
    {
	double	p = (double)SvNV(ST(0));
	double	df = (double)SvNV(ST(1));
	double	ncp;
#line 104 "CDF.xs"
	int which=2, status;
	double t, q, bound;
#line 173 "CDF.c"
	SV *	RETVAL;

	if (items < 3)
	    ncp = 0.0;
	else {
	    ncp = (double)SvNV(ST(2));
	}
#line 107 "CDF.xs"
	q = 1.0 - p;
	ST(0) = sv_newmortal();
	(void)cdftnc(&which, &p, &q, &t, &df, &ncp, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)t );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 191 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_pbeta); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_pbeta)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Math::CDF::pbeta(x, a, b)");
    {
	double	x = (double)SvNV(ST(0));
	double	a = (double)SvNV(ST(1));
	double	b = (double)SvNV(ST(2));
#line 123 "CDF.xs"
	int which=1, status;
	double y, p, q, bound;
#line 210 "CDF.c"
	SV *	RETVAL;
#line 126 "CDF.xs"
	y = 1.0 - x;
	ST(0) = sv_newmortal();
	(void)cdfbet(&which, &p, &q, &x, &y, &a, &b, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)p );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 222 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_qbeta); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_qbeta)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Math::CDF::qbeta(p, a, b)");
    {
	double	p = (double)SvNV(ST(0));
	double	a = (double)SvNV(ST(1));
	double	b = (double)SvNV(ST(2));
#line 142 "CDF.xs"
	int which=2, status;
	double x, y, q, bound;
#line 241 "CDF.c"
	SV *	RETVAL;
#line 145 "CDF.xs"
	q = 1.0 - p;
	ST(0) = sv_newmortal();
	(void)cdfbet(&which, &p, &q, &x, &y, &a, &b, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)x );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 253 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_pchisq); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_pchisq)
{
    dXSARGS;
    if (items < 2 || items > 3)
	Perl_croak(aTHX_ "Usage: Math::CDF::pchisq(x, df, ncp = 0.0)");
    {
	double	x = (double)SvNV(ST(0));
	double	df = (double)SvNV(ST(1));
	double	ncp;
#line 161 "CDF.xs"
	int which=1, status;
	double p, q, bound;
#line 272 "CDF.c"
	SV *	RETVAL;

	if (items < 3)
	    ncp = 0.0;
	else {
	    ncp = (double)SvNV(ST(2));
	}
#line 164 "CDF.xs"
	ST(0) = sv_newmortal();
	(void)cdfchn(&which, &p, &q, &x, &df, &ncp, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)p );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 289 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_qchisq); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_qchisq)
{
    dXSARGS;
    if (items < 2 || items > 3)
	Perl_croak(aTHX_ "Usage: Math::CDF::qchisq(p, df, ncp = 0.0)");
    {
	double	p = (double)SvNV(ST(0));
	double	df = (double)SvNV(ST(1));
	double	ncp;
#line 179 "CDF.xs"
	int which=2, status;
	double x, q, bound;
#line 308 "CDF.c"
	SV *	RETVAL;

	if (items < 3)
	    ncp = 0.0;
	else {
	    ncp = (double)SvNV(ST(2));
	}
#line 182 "CDF.xs"
	q = 1.0 - p;
	ST(0) = sv_newmortal();
	(void)cdfchn(&which, &p, &q, &x, &df, &ncp, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)x );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 326 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_pf); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_pf)
{
    dXSARGS;
    if (items < 3 || items > 4)
	Perl_croak(aTHX_ "Usage: Math::CDF::pf(f, dfn, dfd, ncp = 0.0)");
    {
	double	f = (double)SvNV(ST(0));
	double	dfn = (double)SvNV(ST(1));
	double	dfd = (double)SvNV(ST(2));
	double	ncp;
#line 199 "CDF.xs"
	int which=1, status;
	double p, q, bound;
#line 346 "CDF.c"
	SV *	RETVAL;

	if (items < 4)
	    ncp = 0.0;
	else {
	    ncp = (double)SvNV(ST(3));
	}
#line 202 "CDF.xs"
	ST(0) = sv_newmortal();
	(void)cdffnc(&which, &p, &q, &f, &dfn, &dfd, &ncp, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)p );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 363 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_qf); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_qf)
{
    dXSARGS;
    if (items < 3 || items > 4)
	Perl_croak(aTHX_ "Usage: Math::CDF::qf(p, dfn, dfd, ncp = 0.0)");
    {
	double	p = (double)SvNV(ST(0));
	double	dfn = (double)SvNV(ST(1));
	double	dfd = (double)SvNV(ST(2));
	double	ncp;
#line 218 "CDF.xs"
	int which=2, status;
	double f, q, bound;
#line 383 "CDF.c"
	SV *	RETVAL;

	if (items < 4)
	    ncp = 0.0;
	else {
	    ncp = (double)SvNV(ST(3));
	}
#line 221 "CDF.xs"
	q = 1.0 - p;
	ST(0) = sv_newmortal();
	(void)cdffnc(&which, &p, &q, &f, &dfn, &dfd, &ncp, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)f );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 401 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_pgamma); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_pgamma)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Math::CDF::pgamma(x, shape, scale)");
    {
	double	x = (double)SvNV(ST(0));
	double	shape = (double)SvNV(ST(1));
	double	scale = (double)SvNV(ST(2));
#line 237 "CDF.xs"
	int which=1, status;
	double p, q, bound;
#line 420 "CDF.c"
	SV *	RETVAL;
#line 240 "CDF.xs"
	ST(0) = sv_newmortal();
	(void)cdfgam(&which, &p, &q, &x, &shape, &scale, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)p );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 431 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_qgamma); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_qgamma)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Math::CDF::qgamma(p, shape, scale)");
    {
	double	p = (double)SvNV(ST(0));
	double	shape = (double)SvNV(ST(1));
	double	scale = (double)SvNV(ST(2));
#line 255 "CDF.xs"
	int which=2, status;
	double x, q, bound;
#line 450 "CDF.c"
	SV *	RETVAL;
#line 258 "CDF.xs"
	q = 1.0 - p;
	ST(0) = sv_newmortal();
	(void)cdfgam(&which, &p, &q, &x, &shape, &scale, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)x );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 462 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_ppois); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_ppois)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Math::CDF::ppois(x, lambda)");
    {
	double	x = (double)SvNV(ST(0));
	double	lambda = (double)SvNV(ST(1));
#line 273 "CDF.xs"
	int which=1, status;
	double p, q, bound;
#line 480 "CDF.c"
	SV *	RETVAL;
#line 276 "CDF.xs"
	ST(0) = sv_newmortal();
	(void)cdfpoi(&which, &p, &q, &x, &lambda, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)p );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 491 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_qpois); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_qpois)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Math::CDF::qpois(p, lambda)");
    {
	double	p = (double)SvNV(ST(0));
	double	lambda = (double)SvNV(ST(1));
#line 290 "CDF.xs"
	int which=2, status;
	double x, q, bound;
#line 509 "CDF.c"
	SV *	RETVAL;
#line 293 "CDF.xs"
	q = 1.0 - p;
	ST(0) = sv_newmortal();
	(void)cdfpoi(&which, &p, &q, &x, &lambda, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)x );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 521 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_pbinom); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_pbinom)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Math::CDF::pbinom(x, n, pr)");
    {
	double	x = (double)SvNV(ST(0));
	double	n = (double)SvNV(ST(1));
	double	pr = (double)SvNV(ST(2));
#line 309 "CDF.xs"
	int which=1, status;
	double p, q, ompr, bound;
#line 540 "CDF.c"
	SV *	RETVAL;
#line 312 "CDF.xs"
	ompr = 1.0 - pr;
	ST(0) = sv_newmortal();
	(void)cdfbin(&which, &p, &q, &x, &n, &pr, &ompr, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)p );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 552 "CDF.c"
    }
    XSRETURN(1);
}


XS(XS_Math__CDF_pnbinom); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__CDF_pnbinom)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Math::CDF::pnbinom(x, n, pr)");
    {
	double	x = (double)SvNV(ST(0));
	double	n = (double)SvNV(ST(1));
	double	pr = (double)SvNV(ST(2));
#line 328 "CDF.xs"
	int which=1, status;
	double ompr, p, q, bound;
#line 571 "CDF.c"
	SV *	RETVAL;
#line 331 "CDF.xs"
	ompr = 1.0 - pr;
	ST(0) = sv_newmortal();
	(void)cdfnbn(&which, &p, &q, &x, &n, &pr, &ompr, &status, &bound);
	if(status == 0) {
		sv_setnv( ST(0), (double)p );
	}
	else{
		ST(0) = &PL_sv_undef;
	}
#line 583 "CDF.c"
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Math__CDF); /* prototype to pass -Wmissing-prototypes */
XS(boot_Math__CDF)
{
    dXSARGS;
    char* file = __FILE__;

    XS_VERSION_BOOTCHECK ;

        newXSproto("Math::CDF::constant", XS_Math__CDF_constant, file, "$$");
        newXSproto("Math::CDF::pnorm", XS_Math__CDF_pnorm, file, "$");
        newXSproto("Math::CDF::qnorm", XS_Math__CDF_qnorm, file, "$");
        newXSproto("Math::CDF::pt", XS_Math__CDF_pt, file, "$$;$");
        newXSproto("Math::CDF::qt", XS_Math__CDF_qt, file, "$$;$");
        newXSproto("Math::CDF::pbeta", XS_Math__CDF_pbeta, file, "$$$");
        newXSproto("Math::CDF::qbeta", XS_Math__CDF_qbeta, file, "$$$");
        newXSproto("Math::CDF::pchisq", XS_Math__CDF_pchisq, file, "$$;$");
        newXSproto("Math::CDF::qchisq", XS_Math__CDF_qchisq, file, "$$;$");
        newXSproto("Math::CDF::pf", XS_Math__CDF_pf, file, "$$$;$");
        newXSproto("Math::CDF::qf", XS_Math__CDF_qf, file, "$$$;$");
        newXSproto("Math::CDF::pgamma", XS_Math__CDF_pgamma, file, "$$$");
        newXSproto("Math::CDF::qgamma", XS_Math__CDF_qgamma, file, "$$$");
        newXSproto("Math::CDF::ppois", XS_Math__CDF_ppois, file, "$$");
        newXSproto("Math::CDF::qpois", XS_Math__CDF_qpois, file, "$$");
        newXSproto("Math::CDF::pbinom", XS_Math__CDF_pbinom, file, "$$$");
        newXSproto("Math::CDF::pnbinom", XS_Math__CDF_pnbinom, file, "$$$");
    XSRETURN_YES;
}
