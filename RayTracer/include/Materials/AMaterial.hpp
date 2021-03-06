/*
** RayTracer Copyright (C) 2020 Maxime Houis, Pierre Langlois
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <optional>

#include "Engine/Vector/Vector3.hpp"
#include "Engine/Ray/Ray.hpp"

using RayTraceOpt = std::optional<std::pair<const raylib::Ray, raymath::Vector3>>;

class AMaterial {
protected:
    raymath::Vector3 m_attenuation{};

    bool m_opaque{};
    float m_gammaCorrection{};
    float m_reflectionFactor{};
    float m_refractionFactor{};
public:
    AMaterial() = default;
    AMaterial(const raymath::Vector3 &attenuation, bool opaque, float gammaCorrection, float reflectionFactor, float refractionFactor);
    virtual ~AMaterial();

    [[nodiscard]] virtual RayTraceOpt reflect(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept;
    [[nodiscard]] virtual RayTraceOpt refract(const raylib::Ray &ray, raylib::RayHitInfo &info) const noexcept;
    [[nodiscard]] virtual raymath::Vector3 emit();

    virtual void setOpaque(bool opaque) noexcept final;
    virtual void setGammaCorrection(float gammaCorrection) noexcept final;
    virtual void setReflectionFactor(float reflectionFactor) noexcept final;
    virtual void setRefractionFactor(float refractionFactor) noexcept final;
    [[nodiscard]] virtual bool isOpaque() const noexcept final;
    [[nodiscard]] virtual float getGammaCorrection() const noexcept final;
    [[nodiscard]] virtual float getReflectionFactor() const noexcept final;
    [[nodiscard]] virtual float getRefractionFactor() const noexcept final;

    virtual void setAttenuation(const raymath::Vector3 &attenuation) noexcept final;
    [[nodiscard]] virtual raymath::Vector3 getAttenuation() const noexcept final;
};
