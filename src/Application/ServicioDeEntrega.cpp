#include "ServicioDeEntrega.hpp"

void ServicioDeEntrega::registrarEntrega(const std::string& numeroDeOrden, const EvidenciaDeEntrega& evidencia) {
    uow_.iniciar();
    try {
        OrdenDeServicio orden = ordenes_.obtenerPorNumero(numeroDeOrden);
        orden.registrarEntrega(evidencia);
        ordenes_.guardar(orden);
        uow_.confirmar();
    } catch (...) {
        uow_.revertir();
        throw;
    }
}
