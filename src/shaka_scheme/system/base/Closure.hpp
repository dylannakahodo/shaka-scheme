//
// Created by dylan on 9/19/17.
//

#ifndef SHAKA_SCHEME_CLOSURE_H
#define SHAKA_SCHEME_CLOSURE_H

#include "DataPair.hpp"
#include "Environment.hpp"
#include "IProcedure.hpp"

namespace shaka {

    class Closure {

    public:

        /**
         * @brief Copy Constructor for Closure
         * @param other The Closure object to construct this object from.
         */
        Closure(const Closure &other);

        /**
         * @brief Destructor for Closure
         */
        ~Closure();

        /**
         * @brief Constructor for Closure
         * @param body The function body
         * @param env Pointer to an Environment
         * @param variables List of variables
         * @param frame_cont Reference to the current frame
         * @note frame_cont will be used with Continuations
         */
        Closure(ProcedureBody body, EnvPtr env, PairPtr variables, CallFramePtr frame_cont = nullptr);

        /**
         * @brief Returns the function body of the Closure.
         * @return The content stored in the function body field.
         */
        ProcedureBody get_body();

        /**
         * @brief Returns the current CallFrame
         * @return The content stored in the CallFrame field.
         */
        CallFramePtr get_callframe();

    private:
        using ProcedureBody = IProcedure;
        using EnvPtr = std::shared_ptr<Environment>;
        using PairPtr = std::shared_ptr<DataPair>;
        using CallFramePtr = std::shared_ptr<CallFrame>;

        ProcedureBody func_body;
        EnvPtr env;
        PairPtr variables;
        CallFramePtr frame_cont;
    };
}


#endif //SHAKA_SCHEME_CLOSURE_H
