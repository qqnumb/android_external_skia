/*
 * Copyright 2020 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrDitherEffect.fp; do not modify.
 **************************************************************************************************/
#ifndef GrDitherEffect_DEFINED
#define GrDitherEffect_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"

#include "src/gpu/GrFragmentProcessor.h"

class GrDitherEffect : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(std::unique_ptr<GrFragmentProcessor> inputFP,
                                                     float range) {
        if (range == 0.0 || inputFP == nullptr) {
            return inputFP;
        }
        return std::unique_ptr<GrFragmentProcessor>(new GrDitherEffect(std::move(inputFP), range));
    }
    GrDitherEffect(const GrDitherEffect& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "DitherEffect"; }
    float range;

private:
    GrDitherEffect(std::unique_ptr<GrFragmentProcessor> inputFP, float range)
            : INHERITED(kGrDitherEffect_ClassID,
                        (OptimizationFlags)(inputFP ? ProcessorOptimizationFlags(inputFP.get())
                                                    : kAll_OptimizationFlags) &
                                kPreservesOpaqueInput_OptimizationFlag)
            , range(range) {
        SkASSERT(inputFP);
        this->registerChild(std::move(inputFP), SkSL::SampleUsage::PassThrough());
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
#if GR_TEST_UTILS
    SkString onDumpInfo() const override;
#endif
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    typedef GrFragmentProcessor INHERITED;
};
#endif
