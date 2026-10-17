#include <map>
#include "../Domain/Errores.hpp"
#include "../Domain/OrdenDeServicioRepository.hpp"

// Versión en memoria para pruebas. La propuesta real es una base relacional con ORM.
class OrdenDeServicioRepositoryEnMemoria : public OrdenDeServicioRepository {
public:
    OrdenDeServicio obtenerPorNumero(const std::string& numero) override {
        auto it = ordenes_.find(numero);
        if (it == ordenes_.end()) throw OrdenNoEncontrada();
        return it->second;
    }
    void guardar(const OrdenDeServicio& orden) override {
        ordenes_.insert_or_assign(orden.numero(), orden);
    }
private:
    std::map<std::string, OrdenDeServicio> ordenes_;
};
