// Copyright (c) 2012-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "scenario.h"

class SystemScenarioModule : public ScenarioModule
{
public:
    SystemScenarioModule();

    virtual void    programControlVolume();
    virtual void    programMuted();

    // eDTMF, efeedback
    void            programSystemVolumes(bool ramp);

    //! Calculate volume adjusted for current situation
    int                getAdjustedSystemVolume(bool alertStarting = false) const;

    void            onSinkChanged (EVirtualSink sink, EControlEvent event);

    unsigned long    getNewSessionId();

protected:
    unsigned long    mSessionId;
    Volume            mSystemVolume;
};


SystemScenarioModule * getSystemModule();

#endif // _SYSTEM_H_
