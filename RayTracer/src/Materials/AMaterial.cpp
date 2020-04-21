/*
** RayTracer Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Materials/AMaterial.hpp"

AMaterial::AMaterial()
= default;

AMaterial::AMaterial(const raymath::Vector3 &attenuation)
        : m_attenuation(attenuation)
{
}

AMaterial::~AMaterial()
= default;

void AMaterial::setAttenuation(const raymath::Vector3 &attenuation) noexcept
{
    m_attenuation = attenuation;
}

raymath::Vector3 AMaterial::getAttenuation() const noexcept
{
    return m_attenuation;
}