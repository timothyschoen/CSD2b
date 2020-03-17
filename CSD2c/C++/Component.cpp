
    template <int nPins, int nInternalNets, int nDigipins>
    int Component<nPins, nInternalNets, nDigipins>::pinCount()
    {
        return nPins;
    }


    template <int nPins, int nInternalNets, int nDigipins>
    const int* Component<nPins, nInternalNets, nDigipins>::getPinLocs() const
    {
        return pinLoc;    // This is used for running setupnets!!!! (for linking pinloc to nets)
    }


    template <int nPins, int nInternalNets, int nDigipins>
    const std::vector<std::string> Component<nPins, nInternalNets, nDigipins>::getDigiLocs() const
    {
        return digiPins;
    }


    template <int nPins, int nInternalNets, int nDigipins>
    void Component<nPins, nInternalNets, nDigipins>::setupNets(int & netSize, int & states, const int* pins, const std::vector<std::string> digipins)
    {
        for(int i = 0; i < nPins; ++i)
        {
            nets[i] = pins[i];
        }

        for(int i = 0; i < nDigipins; ++i)
        {
            std::string connections = digipins[i];
            connections.erase(0, 1);
            connections.erase(connections.size()-1, 1);
            std::stringstream ss(connections);
            std::string obj;
            std::vector<int> inputs;
            if(connections.size() > 2)
            {

                while(std::getline(ss,obj,':'))
                {
                    inputs.push_back(std::stoi(obj));
                }
            }
            else if (connections.size() != 0)
            {
                inputs.push_back(std::stoi(connections));
            }

            digiNets[i] = inputs;
        }

        for(int i = 0; i < nInternalNets; ++i)
        {
            nets[nPins + i] = netSize++;
        }

        setupStates(states);
    }
