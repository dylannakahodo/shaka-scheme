//
// Created by dylan on 9/19/17.
//

#include "Closure.hpp"

namespace shaka {

    Closure::Closure(ProcedureBody body, EnvPtr env, PairPtr variables, CallFramePtr frame_cont = nullptr) :
            func_body(body),
            env(env),
            variables(variables),
            frame_cont(frame_cont) {}

    Closure::Closure(const Closure &other) :
            func_body(other.func_body),
            env(other.env),
            variables(other.variables) {}

    Closure::~Closure() {}

    ProcedureBody Closure::get_body() {
        return this->func_body;
    }

    CallFramePtr Closure::get_callframe() {
        if (this->frame_cont != nullptr) {
            return this->frame_cont;
        }
    }

}