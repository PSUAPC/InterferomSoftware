dat = load('mcal.log');

%xform = [0.918399004681497, -0.36128412542635996, 0.16129801274332556;  ...
%    0.3863167693433844, 0.9068728429884036, -0.1683478552706284; ...
%    -0.08545537972606693, 0.21692262990531933, 0.9724412325229908];
%xform = transpose(xform)

ddat = [dat(:,2), dat(:,3), dat(:,4)];

[center, radii, evecs, pars ] = ellipsoid_fit( ddat );

xform = transpose(evecs);

ddat = xform*(transpose(ddat)-center);
center1 = center

[center, radii, evecs, pars ] = ellipsoid_fit( transpose(ddat) );

radii1 = radii;

ddat=[1/radii(1), 0, 0; 0, 1/radii(2), 0; 0, 0 1/radii(3)] * ddat;

[center, radii, evecs, pars ] = ellipsoid_fit( transpose(ddat) );

xform = [1.0/radii1(1), 0, 0; 0, 1.0/radii1(2), 0; 0, 0 1.0/radii1(3)]*xform

ddat1 = [dat(:,2), dat(:,3), dat(:,4)];

ddat = xform*(transpose(ddat1)-center1);

[center, radii, evecs, pars ] = ellipsoid_fit( transpose(xform*(transpose(ddat1)-center1)) )





