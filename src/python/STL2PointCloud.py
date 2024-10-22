import vtk
import open3d as o3d

# --- 1. Read the STL file using VTK ---
reader = vtk.vtkSTLReader()
reader.SetFileName("3d_data/20241021/20x_02.stl")  # Replace with your STL file path
reader.Update()

# --- 2. Convert VTK PolyData to Open3D TriangleMesh ---
polydata = reader.GetOutput()

vertices = []
for i in range(polydata.GetNumberOfPoints()):
    vertices.append(polydata.GetPoint(i))

triangles = []
for i in range(polydata.GetNumberOfCells()):
    cell = polydata.GetCell(i)
    triangles.append([cell.GetPointId(0), cell.GetPointId(1), cell.GetPointId(2)])
    print(cell.GetPointId(0))

mesh = o3d.geometry.TriangleMesh()
mesh.vertices = o3d.utility.Vector3dVector(vertices)
mesh.triangles = o3d.utility.Vector3iVector(triangles)

# --- 3. Sample points from the mesh to create a point cloud ---
pcd = mesh.sample_points_poisson_disk(number_of_points=10000000) 

# --- 4. Save the point cloud as a PCD file ---
o3d.io.write_point_cloud("your_model.pcd", pcd)

# --- 5. Visualize the point cloud ---
o3d.visualization.draw_geometries([pcd])