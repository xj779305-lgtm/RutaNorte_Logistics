#pragma once
#include <string>
#include "OrdenDeServicio.hpp"

class OrdenDeServicioRepository {
public:
    virtual ~OrdenDeServicioRepository() = default;
    virtual OrdenDeServicio obtenerPorNumero(const std::string& numero) = 0;
    virtual void guardar(const OrdenDeServicio& orden) = 0;
};
