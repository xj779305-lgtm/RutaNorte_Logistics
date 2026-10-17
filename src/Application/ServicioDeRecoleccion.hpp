#include <string>
#include "../Domain/OrdenDeServicioRepository.hpp"
#include "IUnidadDeTrabajo.hpp"

// Application Service (CU-03).
class ServicioDeRecoleccion {
public:
    ServicioDeRecoleccion(OrdenDeServicioRepository& ordenes, IUnidadDeTrabajo& unidadDeTrabajo)
        : ordenes_(ordenes), uow_(unidadDeTrabajo) {}

    void rechazarMercancia(const std::string& numeroDeOrden, const std::string& tipoDeDiscrepancia, int cantidadDeFotos);

private:
    OrdenDeServicioRepository& ordenes_;
    IUnidadDeTrabajo& uow_;
};
