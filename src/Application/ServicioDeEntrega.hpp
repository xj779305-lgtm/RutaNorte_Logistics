#include <string>
#include "../Domain/EvidenciaDeEntrega.hpp"
#include "../Domain/OrdenDeServicioRepository.hpp"
#include "IUnidadDeTrabajo.hpp"

// Application Service (CU-04). Solo coordina; las reglas viven en OrdenDeServicio.
class ServicioDeEntrega {
public:
    ServicioDeEntrega(OrdenDeServicioRepository& ordenes, IUnidadDeTrabajo& unidadDeTrabajo)
        : ordenes_(ordenes), uow_(unidadDeTrabajo) {}

    void registrarEntrega(const std::string& numeroDeOrden, const EvidenciaDeEntrega& evidencia);

private:
    OrdenDeServicioRepository& ordenes_;
    IUnidadDeTrabajo& uow_;
};
