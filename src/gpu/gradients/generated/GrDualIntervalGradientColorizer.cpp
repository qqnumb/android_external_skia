/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrDualIntervalGradientColorizer.fp; do not modify.
 **************************************************************************************************/
#include "GrDualIntervalGradientColorizer.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLDualIntervalGradientColorizer : public GrGLSLFragmentProcessor {
public:
    GrGLSLDualIntervalGradientColorizer() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrDualIntervalGradientColorizer& _outer =
                args.fFp.cast<GrDualIntervalGradientColorizer>();
        (void)_outer;
        auto scale01 = _outer.scale01;
        (void)scale01;
        auto bias01 = _outer.bias01;
        (void)bias01;
        auto scale23 = _outer.scale23;
        (void)scale23;
        auto bias23 = _outer.bias23;
        (void)bias23;
        auto threshold = _outer.threshold;
        (void)threshold;
        scale01Var = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag,
                                                      kFloat4_GrSLType, "scale01");
        bias01Var = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag,
                                                     kFloat4_GrSLType, "bias01");
        scale23Var = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag,
                                                      kFloat4_GrSLType, "scale23");
        bias23Var = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag,
                                                     kFloat4_GrSLType, "bias23");
        thresholdVar = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag,
                                                        kHalf_GrSLType, "threshold");
        fragBuilder->codeAppendf(
                R"SkSL(half t = half(%s.x);
float4 scale, bias;
if (t < %s) {
    scale = %s;
    bias = %s;
} else {
    scale = %s;
    bias = %s;
}
%s = half4(float(t) * scale + bias);
)SkSL",
                args.fSampleCoord, args.fUniformHandler->getUniformCStr(thresholdVar),
                args.fUniformHandler->getUniformCStr(scale01Var),
                args.fUniformHandler->getUniformCStr(bias01Var),
                args.fUniformHandler->getUniformCStr(scale23Var),
                args.fUniformHandler->getUniformCStr(bias23Var), args.fOutputColor);
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {
        const GrDualIntervalGradientColorizer& _outer =
                _proc.cast<GrDualIntervalGradientColorizer>();
        {
            const SkPMColor4f& scale01Value = _outer.scale01;
            if (scale01Prev != scale01Value) {
                scale01Prev = scale01Value;
                pdman.set4fv(scale01Var, 1, scale01Value.vec());
            }
            const SkPMColor4f& bias01Value = _outer.bias01;
            if (bias01Prev != bias01Value) {
                bias01Prev = bias01Value;
                pdman.set4fv(bias01Var, 1, bias01Value.vec());
            }
            const SkPMColor4f& scale23Value = _outer.scale23;
            if (scale23Prev != scale23Value) {
                scale23Prev = scale23Value;
                pdman.set4fv(scale23Var, 1, scale23Value.vec());
            }
            const SkPMColor4f& bias23Value = _outer.bias23;
            if (bias23Prev != bias23Value) {
                bias23Prev = bias23Value;
                pdman.set4fv(bias23Var, 1, bias23Value.vec());
            }
            float thresholdValue = _outer.threshold;
            if (thresholdPrev != thresholdValue) {
                thresholdPrev = thresholdValue;
                pdman.set1f(thresholdVar, thresholdValue);
            }
        }
    }
    SkPMColor4f scale01Prev = {SK_FloatNaN, SK_FloatNaN, SK_FloatNaN, SK_FloatNaN};
    SkPMColor4f bias01Prev = {SK_FloatNaN, SK_FloatNaN, SK_FloatNaN, SK_FloatNaN};
    SkPMColor4f scale23Prev = {SK_FloatNaN, SK_FloatNaN, SK_FloatNaN, SK_FloatNaN};
    SkPMColor4f bias23Prev = {SK_FloatNaN, SK_FloatNaN, SK_FloatNaN, SK_FloatNaN};
    float thresholdPrev = SK_FloatNaN;
    UniformHandle scale01Var;
    UniformHandle bias01Var;
    UniformHandle scale23Var;
    UniformHandle bias23Var;
    UniformHandle thresholdVar;
};
GrGLSLFragmentProcessor* GrDualIntervalGradientColorizer::onCreateGLSLInstance() const {
    return new GrGLSLDualIntervalGradientColorizer();
}
void GrDualIntervalGradientColorizer::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                                            GrProcessorKeyBuilder* b) const {}
bool GrDualIntervalGradientColorizer::onIsEqual(const GrFragmentProcessor& other) const {
    const GrDualIntervalGradientColorizer& that = other.cast<GrDualIntervalGradientColorizer>();
    (void)that;
    if (scale01 != that.scale01) return false;
    if (bias01 != that.bias01) return false;
    if (scale23 != that.scale23) return false;
    if (bias23 != that.bias23) return false;
    if (threshold != that.threshold) return false;
    return true;
}
GrDualIntervalGradientColorizer::GrDualIntervalGradientColorizer(
        const GrDualIntervalGradientColorizer& src)
        : INHERITED(kGrDualIntervalGradientColorizer_ClassID, src.optimizationFlags())
        , scale01(src.scale01)
        , bias01(src.bias01)
        , scale23(src.scale23)
        , bias23(src.bias23)
        , threshold(src.threshold) {
    this->cloneAndRegisterAllChildProcessors(src);
    this->setUsesSampleCoordsDirectly();
}
std::unique_ptr<GrFragmentProcessor> GrDualIntervalGradientColorizer::clone() const {
    return std::make_unique<GrDualIntervalGradientColorizer>(*this);
}
#if GR_TEST_UTILS
SkString GrDualIntervalGradientColorizer::onDumpInfo() const {
    return SkStringPrintf(
            "(scale01=float4(%f, %f, %f, %f), bias01=float4(%f, %f, %f, %f), scale23=float4(%f, "
            "%f, %f, %f), bias23=float4(%f, %f, %f, %f), threshold=%f)",
            scale01.fR, scale01.fG, scale01.fB, scale01.fA, bias01.fR, bias01.fG, bias01.fB,
            bias01.fA, scale23.fR, scale23.fG, scale23.fB, scale23.fA, bias23.fR, bias23.fG,
            bias23.fB, bias23.fA, threshold);
}
#endif

std::unique_ptr<GrFragmentProcessor> GrDualIntervalGradientColorizer::Make(const SkPMColor4f& c0,
                                                                           const SkPMColor4f& c1,
                                                                           const SkPMColor4f& c2,
                                                                           const SkPMColor4f& c3,
                                                                           float threshold) {
    // Derive scale and biases from the 4 colors and threshold
    auto vc0 = Sk4f::Load(c0.vec());
    auto vc1 = Sk4f::Load(c1.vec());
    auto scale01 = (vc1 - vc0) / threshold;
    // bias01 = c0

    auto vc2 = Sk4f::Load(c2.vec());
    auto vc3 = Sk4f::Load(c3.vec());
    auto scale23 = (vc3 - vc2) / (1 - threshold);
    auto bias23 = vc2 - threshold * scale23;

    return std::unique_ptr<GrFragmentProcessor>(new GrDualIntervalGradientColorizer(
            {scale01[0], scale01[1], scale01[2], scale01[3]}, c0,
            {scale23[0], scale23[1], scale23[2], scale23[3]},
            {bias23[0], bias23[1], bias23[2], bias23[3]}, threshold));
}
