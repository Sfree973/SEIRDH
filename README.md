# SEIRDH
This resource is paper "Impacts of detection and contact tracing on the epidemic spread in time-varying networks" source code program. Our resources are used only for learning and communication. 
 
The source program is developed based on C language and runs on Visual Studio 2019. The source program mainly includes two parts, one is  numerical simulations on artificial networks, the other is numerical simulations on real networks. 

In the artificial networks part,  the "Activity" file includes node's activity required for heterogeneous distribution and homogeneous distribution networks, the "Exposed individuals have no infected ability" file and the "Exposed individuals have infected ability" file
mainly perform experiments under the condition that the exposed individuals have infectivity or not, respectively.

In the real networks part,  the ''Real data set'' and "Null model data" respectively represent the real data set and null model data set. Null model data is obtained by randoming the real networks, that is performed by retaining the order of activation time for each node, the integration degree distribution for the final 
time, and the degree distribution at each time step. In addition, the other files perform experiments under different contact tracing modes.




