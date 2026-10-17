#include "ServicioDeRecoleccion.hpp"

void ServicioDeRecoleccion::rechazarMercancia(const std::string& numeroDeOrden,
                                              const std::string& tipoDeDiscrepancia, int cantidadDeFotos) {
    uow_.iniciar();
    try {
        OrdenDeServicio orden = ordenes_.obtenerPorNumero(numeroDeOrden);
        orden.rechazarMercancia(tipoDeDiscrepancia, cantidadDeFotos);
        ordenes_.guardar(orden);
        uow_.confirmar();
    } catch (...) {
        uow_.revertir();
        throw;
    }
}
