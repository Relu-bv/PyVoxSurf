/*
 *   Copyright (c) 2012, Michael Lehn, Klaus Pototzky
 *
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1) Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2) Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *   3) Neither the name of the FLENS development group nor the names of
 *      its contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CXXLAPACK_INTERFACE_SYTRS2_TCC
#define CXXLAPACK_INTERFACE_SYTRS2_TCC 1

#include <iostream>
#include "xflens/cxxlapack/interface/interface.h"
#include "xflens/cxxlapack/netlib/netlib.h"

namespace cxxlapack {

template <typename IndexType>
IndexType
sytrs2(char                  uplo,
       IndexType             n,
       IndexType             nRhs,
       const float           *A,
       IndexType             ldA,
       const IndexType       *iPiv,
       float                 *B,
       IndexType             ldB,
       float                 *work)
{
    CXXLAPACK_DEBUG_OUT("ssyrts2");

    IndexType info;
    LAPACK_IMPL(ssytrs2)(&uplo,
                        &n,
                        &nRhs,
                        A,
                        &ldA,
                        iPiv,
                        B,
                        &ldB,
                        work,
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}


template <typename IndexType>
IndexType
sytrs2(char                  uplo,
       IndexType             n,
       IndexType             nRhs,
       const double          *A,
       IndexType             ldA,
       const IndexType       *iPiv,
       double                *B,
       IndexType             ldB,
       double                *work)
{
    CXXLAPACK_DEBUG_OUT("dsyrts2");

    IndexType info;
    LAPACK_IMPL(dsytrs2)(&uplo,
                        &n,
                        &nRhs,
                        A,
                        &ldA,
                        iPiv,
                        B,
                        &ldB,
                        work,
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}

template <typename IndexType>
IndexType
sytrs2(char                        uplo,
       IndexType                   n,
       IndexType                   nRhs,
       const std::complex<float >  *A,
       IndexType                   ldA,
       const IndexType             *iPiv,
       std::complex<float >        *B,
       IndexType                   ldB,
       std::complex<float >        *work)
{
    CXXLAPACK_DEBUG_OUT("csyrts2");

    IndexType info;
    LAPACK_IMPL(csytrs2)(&uplo,
                        &n,
                        &nRhs,
                        reinterpret_cast<const float  *>(A),
                        &ldA,
                        iPiv,
                        reinterpret_cast<float  *>(B),
                        &ldB,
                        reinterpret_cast<float  *>(work),
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}

template <typename IndexType>
IndexType
sytrs2(char                        uplo,
       IndexType                   n,
       IndexType                   nRhs,
       const std::complex<double>  *A,
       IndexType                   ldA,
       const IndexType             *iPiv,
       std::complex<double>        *B,
       IndexType                   ldB,
       std::complex<double>        *work)
{
    CXXLAPACK_DEBUG_OUT("zsyrts2");

    IndexType info;
    LAPACK_IMPL(zsytrs2)(&uplo,
                        &n,
                        &nRhs,
                        reinterpret_cast<const double *>(A),
                        &ldA,
                        iPiv,
                        reinterpret_cast<double *>(B),
                        &ldB,
                        reinterpret_cast<double *>(work),
                        &info);
#   ifndef NDEBUG
    if (info<0) {
        std::cerr << "info = " << info << std::endl;
    }
#   endif
    ASSERT(info>=0);
    return info;
}

} // namespace cxxlapack

#endif // CXXLAPACK_INTERFACE_SYTRS2_TCC
